#include <iostream>
#include <stdlib.h>
#include <speechapi_cxx.h>
#include <windows.h>
#include <conio.h>
#include <regex>
#include <curl\curl.h>
#include <json/json.h>

using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;
using namespace Microsoft::CognitiveServices::Speech::Translation;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

std::string getImageURL(const std::string& query, const std::string API_BASE_URL, const std::string API_KEY) {
    CURL* curl;
    CURLcode resultado;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::string url = API_BASE_URL + "?query=" + query + "&client_id=" + API_KEY;
        std::string response;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        resultado = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        if (resultado != CURLE_OK) {
            std::cerr << "Error in cURL request: " << curl_easy_strerror(resultado) << std::endl;
            return "";
        }

        Json::Value root;
        Json::CharReaderBuilder builder;
        std::istringstream json_stream(response);

        if (Json::parseFromStream(builder, json_stream, &root, nullptr)) {
            
            if (root.isMember("results") && root["results"].isArray() && !root["results"].empty()) {
                
                const Json::Value& firstResult = root["results"][0];
                if (!firstResult["urls"]["raw"].isNull()) {
                    std::string imageURL = firstResult["urls"]["raw"].asString();
                    return imageURL;
                }
                else {
                    std::cout << "No se pudo extraer la imagen del JSON." << std::endl;
                    return "";
                }
            }
            else {
                std::cout << "Array 'resultados' invalido en el JSON." << std::endl;
                return "";
            }
        }
        else {
            std::cout << "No se pudo parsear el JSON." << std::endl;
            return "";
        }

        
    }

}

void mostrarMenu(int opcion) {
    system("cls");
    std::cout << "\n--------------TRADUCTOR CON IMAGENES-----------------\n";
    std::cout << "\nSeleccione una opcion:\n\n";
    std::cout << (opcion == 1 ? "> " : "  ") << "Traduzca de espanol a ingles\n";
    std::cout << (opcion == 2 ? "> " : "  ") << "Traduzca de ingles a espanol\n";
    std::cout << (opcion == 3 ? "> " : "  ") << "Salir\n";
}


int main() {

    int opcion = 1;
    char tecla;

    const std::string API_BASE_URL = "https://api.unsplash.com/search/photos/";
    const std::string API_KEY = "tu--llave-para-unsplash";

    std::string my_key = "tu-llave-para-azure";
    std::string my_region_key = "eastus";

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    do {
        mostrarMenu(opcion);
        tecla = _getch();

        switch (tecla) {
        case 72: // Flecha arriba
            if (opcion > 1) opcion--;
            break;
        case 80: // Flecha abajo
            if (opcion < 3) opcion++;
            break;
        case 13: // Enter
            if (opcion == 1) {
                cursorInfo.bVisible = true;
                SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                auto transConfig = SpeechTranslationConfig::FromSubscription(my_key, my_region_key);
                transConfig->SetSpeechRecognitionLanguage("es-ES");
                transConfig->AddTargetLanguage("en-US");

                auto audioConfig = AudioConfig::FromDefaultMicrophoneInput();

                auto transRecognizer = TranslationRecognizer::FromConfig(transConfig, audioConfig);

                auto configuracion1 = SpeechConfig::FromSubscription(my_key, my_region_key);
                configuracion1->SetSpeechSynthesisLanguage("es-ES");
                auto sintetizador1 = SpeechSynthesizer::FromConfig(configuracion1);
                sintetizador1->SpeakText("Di la palabra que quieres traducir.");

                auto configuracion2 = SpeechConfig::FromSubscription(my_key, my_region_key);
                configuracion2->SetSpeechSynthesisLanguage("en-US");
                auto sintetizador2 = SpeechSynthesizer::FromConfig(configuracion2);
                auto result2 = transRecognizer->RecognizeOnceAsync().get();

                std::string palabra = result2->Text;

                std::cout << palabra << std::endl;

                if (result2->Reason == ResultReason::TranslatedSpeech)
                {

                    sintetizador1->SpeakText("La traduccion es: ");

                    auto translations = result2->Translations;
                    for (const auto& pair : translations) {
                        sintetizador2->SpeakText(pair.second.c_str());
                        palabra = pair.second.c_str();
                    }

                    printf("\n");

                    std::string imageURL = getImageURL(palabra, API_BASE_URL, API_KEY);

                    if (!imageURL.empty()) {
                        std::cout << "Image URL: " << imageURL << std::endl;

                        std::wstring wideURL(imageURL.begin(), imageURL.end());

                        ShellExecuteW(nullptr, L"open", wideURL.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

                    }

                }
                else if (result2->Reason == ResultReason::NoMatch)
                {
                    std::cout << "NOMATCH: Speech could not be recognized." << std::endl;
                }
                else if (result2->Reason == ResultReason::Canceled)
                {
                    auto cancellation = CancellationDetails::FromResult(result2);
                    std::cout << "CANCELED: Reason=" << (int)cancellation->Reason << std::endl;

                    if (cancellation->Reason == CancellationReason::Error)
                    {
                        std::cout << "CANCELED: ErrorCode=" << (int)cancellation->ErrorCode << std::endl;
                        std::cout << "CANCELED: ErrorDetails=" << cancellation->ErrorDetails << std::endl;
                        std::cout << "CANCELED: Did you set the speech resource key and region values?" << std::endl;
                    }
                }

                system("pause");

                cursorInfo.bVisible = false;
                SetConsoleCursorInfo(consoleHandle, &cursorInfo);
            }
            else if (opcion == 2) {
                cursorInfo.bVisible = true;
                SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                auto transConfig = SpeechTranslationConfig::FromSubscription(my_key, my_region_key);
                transConfig->SetSpeechRecognitionLanguage("en-US");
                transConfig->AddTargetLanguage("es-ES");

                auto audioConfig = AudioConfig::FromDefaultMicrophoneInput();

                auto transRecognizer = TranslationRecognizer::FromConfig(transConfig, audioConfig);

                auto configuracion1 = SpeechConfig::FromSubscription(my_key, my_region_key);
                configuracion1->SetSpeechSynthesisLanguage("es-ES");
                auto sintetizador1 = SpeechSynthesizer::FromConfig(configuracion1);
                sintetizador1->SpeakText("Di la palabra que quieres traducir.");

                auto configuracion2 = SpeechConfig::FromSubscription(my_key, my_region_key);
                configuracion2->SetSpeechSynthesisLanguage("en-US");
                auto sintetizador2 = SpeechSynthesizer::FromConfig(configuracion2);
                auto result2 = transRecognizer->RecognizeOnceAsync().get();

                std::string palabra = result2->Text;

                std::cout << palabra << std::endl;

                    if (result2->Reason == ResultReason::TranslatedSpeech)
                    {

                        sintetizador1->SpeakText("La traduccion es: ");

                        auto translations = result2->Translations;
                        for (const auto& pair : translations) {
                            sintetizador2->SpeakText(pair.second.c_str());
                        }

                        printf("\n");

                        std::string imageURL = getImageURL(palabra, API_BASE_URL, API_KEY);

                        if (!imageURL.empty()) {
                            std::cout << "Image URL: " << imageURL << std::endl;

                            std::wstring wideURL(imageURL.begin(), imageURL.end());

                            ShellExecuteW(nullptr, L"open", wideURL.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

                        }

                    }
                    else if (result2->Reason == ResultReason::NoMatch)
                    {
                        std::cout << "NOMATCH: Speech could not be recognized." << std::endl;
                    }
                    else if (result2->Reason == ResultReason::Canceled)
                    {
                        auto cancellation = CancellationDetails::FromResult(result2);
                        std::cout << "CANCELED: Reason=" << (int)cancellation->Reason << std::endl;

                        if (cancellation->Reason == CancellationReason::Error)
                        {
                            std::cout << "CANCELED: ErrorCode=" << (int)cancellation->ErrorCode << std::endl;
                            std::cout << "CANCELED: ErrorDetails=" << cancellation->ErrorDetails << std::endl;
                            std::cout << "CANCELED: Did you set the speech resource key and region values?" << std::endl;
                        }
                    }
                
                system("pause");


                cursorInfo.bVisible = false;
                SetConsoleCursorInfo(consoleHandle, &cursorInfo);
            }
            else if (opcion == 3) {
                system("cls");
                std::cout << "Saliendo del programa." << std::endl;
                exit(0);
            }
            break;
        default:
            break;
        }
    } while (true);

    system("pause");
    return 0;
}
