#include "ask.h"
#include "users.h"

void data_test(askSystem &sys)
{
    std::cout << "TEST DATA ...\n";
    sys.load_data_base();
    std::map<std::string, User> users = sys.user_manager.get_users_login_info();
    for(const auto& u : users)
    {
        std::cout << u.first << "\n";
    }
}


int main()
{
    askSystem system;
    data_test(system);
    return 0;
}

