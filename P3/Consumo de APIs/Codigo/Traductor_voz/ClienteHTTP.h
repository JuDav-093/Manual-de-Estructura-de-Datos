#pragma once

#include <iostream>
#include <windows.h>
#include <string.h>
#include <curl/curl.h>

std::string formatear_http(std::string original) {
    std::string formateado = original;
    if (original.find(' ') != std::string::npos) {
        std::replace(formateado.begin(), formateado.end(), ' ', '+');
    }
    return formateado;
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

std::string obtener_url(std::string respuesta) {
    char actual;
    std::string url = "";
    int primera_url_pos = respuesta.find("raw");
    primera_url_pos += 6;
    actual = respuesta.at(primera_url_pos);
    while (actual != '\\'){
        url += actual;
        primera_url_pos++;
        actual = respuesta.at(primera_url_pos);
    }
    return url;
}

bool buscar_imagen(std::string palabra_busqueda) {
	CURL* curl = curl_easy_init();
    CURLcode resultado;

	if (curl) {
        
        const std::string API_BASE_URL = "https://api.unsplash.com/search/photos/";
        
        
        std::string apiKey = "vxPusnSMuFbeDrsfTJNswbZtpeIdzOhrgsD3MdnaXc4"; 
        
        std::string url = API_BASE_URL + "?page=1&per_page=1" + "&query=" + palabra_busqueda + "&client_id=" + apiKey;
        std::string response;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        resultado = curl_easy_perform(curl);

        if (resultado == CURLE_OK) {
            std::string url = obtener_url(response);
            std::wstring wurl(url.begin(), url.end());

            HINSTANCE result = ShellExecuteW(nullptr, L"open", wurl.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
            curl_easy_cleanup(curl);
            return true;
        }
        else {
            std::cerr << "Error al realizar la solicitud: " << curl_easy_strerror(resultado) << std::endl;
            curl_easy_cleanup(curl);
            return false;
        }
        
	}
	else {
		return false;
	}
}

std::string obtener_traduccion(std::string respuesta_API) {
    std::string traduccion;
    traduccion = respuesta_API.substr(respuesta_API.find("text"), respuesta_API.length());
    traduccion = traduccion.substr(traduccion.find(':'), traduccion.find("\"}"));
    traduccion = traduccion.substr(traduccion.find('"')+1, traduccion.length());
    traduccion = traduccion.substr(0, traduccion.find('"'));
    return traduccion;
}

std::string traducir(std::string a_traducir, std::string lenguaje_original, std::string lenguaje_objetivo) {
    CURL* curl = curl_easy_init();
    std::string traduccion = "";
    if (curl) {
        const std::string API_BASE_URL = "https://api-free.deepl.com/v2/translate";
        std::string apiKey = "21bf1484-11aa-4767-9a4a-90849ba0c71b:fx";
        std::string postData = "text=" + a_traducir + "&source_lang=" + lenguaje_original + "&target_lang=" + lenguaje_objetivo;
        
        curl_easy_setopt(curl, CURLOPT_URL, API_BASE_URL.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: DeepL-Auth-Key " + apiKey).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
        std::string response;

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            traduccion = obtener_traduccion(response);
        }
        else {
            std::cerr << "Error al realizar la solicitud: " << curl_easy_strerror(res) << std::endl;
            
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        
    }
    else {
        std::cerr << "Error al abrir cURL" << std::endl;
    }

    return traduccion;
}