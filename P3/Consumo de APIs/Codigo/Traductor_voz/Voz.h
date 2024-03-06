#pragma once

#include <speechapi_cxx.h>

using namespace Microsoft::CognitiveServices::Speech;

bool generar_voz(const std::string texto) {
    try {
        const std::string subscriptionKey = "355f7a9209ef42df8446b89eb812ba21";
        const std::string serviceRegion = "eastus";

        auto configuracion = SpeechConfig::FromSubscription(subscriptionKey, serviceRegion);

        configuracion->SetSpeechSynthesisLanguage("en-US");

        auto sintetizador = SpeechSynthesizer::FromConfig(configuracion);
        auto result = sintetizador->SpeakText(texto);

        if (result->Reason == ResultReason::SynthesizingAudioCompleted) {
            return true;
        }
        else {
            return false;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return false;
    }
}


std::string capturar_voz() {
    const std::string subscriptionKey = "355f7a9209ef42df8446b89eb812ba21";
    const std::string serviceRegion = "eastus";
    auto config = SpeechConfig::FromSubscription(subscriptionKey, serviceRegion);
    
    config->SetSpeechRecognitionLanguage("es-MX");
    auto recognizer = SpeechRecognizer::FromConfig(config);
    std::cout << "Habla para comenzar el reconocimiento..." << std::endl;
    auto result = recognizer->RecognizeOnceAsync().get();

    if (result->Reason == ResultReason::RecognizedSpeech) {
        std::cout << "Texto reconocido: " << result->Text << std::endl;
    }
    else if (result->Reason == ResultReason::NoMatch) {
        std::cout << "No se reconoció ningún texto." << std::endl;
    }
    else if (result->Reason == ResultReason::Canceled) {
        auto cancellation = CancellationDetails::FromResult(result);
        std::cout << "Cancelado " << std::endl;
    }

    return std::string(result->Text);
}