#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define api_key "993b1d32a2fc4263933142546231612"

// Callback function to handle the response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    printf("%.*s", (int)realsize, (char*)contents);
    return realsize;
}

int main(void) {
    CURL* curl;
    CURLcode res;
    char baseurl[100] = "http://api.weatherapi.com/v1/current.json?key=";
    
    strcat(baseurl,api_key);
    strcat(baseurl,"&q=Karachi&aqi=yes");
    	
    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);	
	
    // Create a curl handle
    curl = curl_easy_init();
    if(curl) {
        // Set the target API URL
        curl_easy_setopt(curl, CURLOPT_URL,baseurl);

        // Set the callback function to handle the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        // Cleanup
        curl_easy_cleanup(curl);
    }

    // Cleanup libcurl
    curl_global_cleanup();

    return 0;
}
