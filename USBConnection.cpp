#include <iostream>
#include <string.h>
#include <stack>


using namespace std;

class USBConnection
{
    private:
        int ID;
        static stack<int> ids;
        USBConnection(int id)
        {
            ID = id;
        }
    public:

        int get_id()
        {
            return ID;
        }

        static USBConnection* CreateUsbConnection()
        {
            if(ids.size()>0)
            {
                int id = USBConnection::ids.top();
                USBConnection::ids.pop();
                USBConnection *newConnection = new USBConnection(id);
                return newConnection;
            }
            else{
                return NULL;
            }
            
        }
        USBConnection()
        {
            ID = ids.top();
            ids.pop();
        }

        ~USBConnection()
        {
            ids.push(ID);  
        }
};

stack<int> USBConnection::ids({3, 2, 1});
