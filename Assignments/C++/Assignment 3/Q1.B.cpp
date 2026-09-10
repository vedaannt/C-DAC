#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers)
{
    cout << "Headers:" << endl;

    for (int i = 0; i < headers.size(); i++)
    {
        cout << " " << headers[i].first
             << " : " << headers[i].second << endl;
    }
}

int main()
{
    RequestId requestId = 1748293847;

    Port serverPort = 8080;

    IPAddress serverIP = "192.168.1.10";

    HeaderList headers =
    {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGci..."},
        {"Accept-Language", "en-US"}
    };

    cout << "Request ID : " << requestId << endl;
    cout << "Server Port : " << serverPort << endl;

    printHeaders(headers);

    return 0;
}