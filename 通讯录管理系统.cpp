#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//设计联系人结构体
struct Person
{
	string m_Name;//姓名
	string m_Sex;//性别
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//地址
};
//设计通讯录结构体
struct AddressBooks
{
	struct Person PersonArray[MAX];//通讯录保存的联系人数组

	int m_Size;//通讯录当前联系人个数
};
void ShowMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
void addPerson(AddressBooks *abs)
{
	//判断通讯录是否超过最大添加人数
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
	}
	else
	{
		//添加具体联系人

	    //姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别" << endl;
		string sex;
		while (true)
		{
			cin >> sex;
			if (sex == "男" || sex == "女")
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		//电话
		string phone;
		cout << "请输入电话号码" << endl;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		//地址
		string address;
		cout << "请输入家庭地址" << endl;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//显示联系人
void ShowPerson(AddressBooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << " 姓名： " << abs->PersonArray[i].m_Name << endl;
			cout << " 性别： " << abs->PersonArray[i].m_Sex << endl;
			cout << " 年龄： " << abs->PersonArray[i].m_Age << endl;
			cout << " 电话号码： " << abs->PersonArray[i].m_Phone << endl;
			cout << " 家庭地址： " << abs->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}

//判断联系人是否存在
int isExist(AddressBooks *abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->PersonArray[i].m_Name == name)
		{
			return i;//返回此人在数组中下标编号
		}
	}
	return -1;
}

//删除联系人
void DeletePerson(AddressBooks *abs,string name)
{
	int ret = isExist(abs, name);
	for (int i = ret; i < abs->m_Size; i++)
	{
		abs->PersonArray[i] = abs->PersonArray[i + 1];
	}
	cout << "删除成功" << endl;
	abs->m_Size--;
	system("pause");//按任意键继续
	system("cls");//清屏
}

//查找特定联系人
void FindPerson(AddressBooks* abs)
{
	string name;
	cout << "请输入要查询联系人" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << " 姓名： " << abs->PersonArray[ret].m_Name << endl;
		cout << " 性别： " << abs->PersonArray[ret].m_Sex << endl;
		cout << " 年龄： " << abs->PersonArray[ret].m_Age << endl;
		cout << " 电话号码： " << abs->PersonArray[ret].m_Phone << endl;
		cout << " 家庭地址： " << abs->PersonArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
//修改联系人
void MonifyPerson(AddressBooks* abs)
{
	string name;
	cout << "输入联系人" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->PersonArray[ret].m_Name = name;

		//性别
		cout << "请输入性别" << endl;
		string sex;
		while (true)
		{
			cin >> sex;
			if (sex == "男" || sex == "女")
			{
				abs->PersonArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[ret].m_Age = age;

		//电话
		string phone;
		cout << "请输入电话号码" << endl;
		cin >> phone;
		abs->PersonArray[ret].m_Phone = phone;

		//地址
		string address;
		cout << "请输入家庭地址" << endl;
		cin >> address;
		abs->PersonArray[ret].m_Addr = address;

		
		cout << "修改成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
	else
	{
		cout << "查无此人" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}
void ClaerPerson(AddressBooks* abs)
{
	abs->m_Size = 0;
	cout << "清除成功" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

int main()
{
	//创建通讯录结构体变量
	AddressBooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		//菜单调用
		ShowMenu();

		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);
			break;

		case 2://显示联系人
			ShowPerson(&abs);
			break;

		case 3://删除联系人
		{
			cout << "请输入联系人" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
				system("pause");//按任意键继续
				system("cls");//清屏
			}
			else
			{
				DeletePerson(&abs, name);
			}
			break;
		}

		case 4://查找联系人
			FindPerson(&abs);
			break;

		case 5://修改联系人
			MonifyPerson(&abs);
			break;

		case 6://清空联系人
			ClaerPerson(&abs);
			break;

		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

 