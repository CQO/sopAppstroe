#ifndef SOPAUTHORCONTROL_H
#define SOPAUTHORCONTROL_H

#include <QObject>
#include "servicecontroller.h"

class SopAuthorControl : public QObject
{
    Q_OBJECT
public:
    explicit SopAuthorControl(QObject *parent = 0);
    int64 login(std::string user,  std::string pwd,  std::string server);
    void  logout();
    void  changePassword(QString oldPwd,QString newPwd);
    void _changePassword(service::ErrorInfo code);
    void _login(service::ErrorInfo code, int64 userId,int64 time, const std::string veryImg);
    void _logout(service::ErrorInfo code);

    void _msgNoticeCb(std::shared_ptr<Msg>msg);
    void _recontactCb(int, std::vector<std::shared_ptr<Chat> >&msgList);

    void updateAccountInfo(Account user);
    void _updateAccountInfo(service::ErrorInfo code);

    void getAccountInfo(Account& info );
    int64 userId();
signals:
    void loginResult(int code);
    void loginoutResult(int code);
    void changePasswordResult(int code);
    void noticeLastMsg(QString msgContent);
    void updateAccountResult(int code);

public slots:
private:
    std::shared_ptr<service::IAuthService> m_pAuthorService;
    std::shared_ptr<service::IChatService> m_pChatService;
    std::shared_ptr<service::IUserService> m_pUserService;
    int64  mUserId;
};

#endif // SOPAUTHORCONTROL_H
