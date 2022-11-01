#include <jsoncpp/json/json.h>
#include "json.hpp"
#include <fstream>
#include <iostream>
#include<json/writer.h>

using namespace std;

int main()
{
    ifstream fJson("Data.json");
    stringstream buffer;
    buffer << fJson.rdbuf();
    auto json = nlohmann::json::parse(buffer.str());

    cout << "\nNumber of questions: " << json["1"]["profile_id"] << "\n";
    cout << "\nNumber of questions: " << json["2"] << "\n";

    for(int i = 0; i < json.size(); i++){
        cout << json[std::to_string(i + 1)] << endl;

    }

    json["1"] = "12";
    std::fstream file("dataDetail.json");
    file << json;
    return 0;
}
