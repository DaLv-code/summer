#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <iostream>
#include "database.h"
using namespace std;

class member : public Database
{
protected:
    string id;
    string pw;
    string name;
    string phone;
    string query;

public:
    static string ID;
    void login();                       // 로그인
    void find_id();                     // 아이디 찾기
    void find_pw();                     // 비밀번호 찾기
    void sign_up();                     // 회원가입
    void change_pw();                   // 비밀번호 변경
    void change_phone();                // 전화번호 변경
    void member::read_tourinfo_area();  // 여행정보 지역이름으로 열람
    void member::read_tourinfo_beach(); // 여행정보 해변명으로 열람
    void member::read_tourinfo_road();  // 여행정보 도로명으로 열람
}

string Member::ID;

#endif