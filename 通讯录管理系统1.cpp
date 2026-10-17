#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//创建联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//联系电话
	string m_Phone;
	//家庭住址
	string m_Addr;
};
//设计通讯录结构体
struct Addressbooks
{	
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};


//添加联系人的函数
void addPerson(Addressbooks * abs)
{
	//判断通讯录是否已满，如果满了，就不在添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，不再添加联系人" << endl;
		return;
	}
	else 
	{
		//添加具体的联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别:" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是1或者2，可以退出循环，因为输入的是正确值
			//如果输入有误，则继续进入循环，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;

		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误!请重新输入" << endl;
		}
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "您已添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}


//显示联系人
void showPerson(Addressbooks*abs)
{
	//先进行判断，如果通讯录人数为空，则为空
	//如果人数大于0，则进行显示联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话号码： " << abs->personArray[i].m_Phone << "\t";
			cout << "家庭住址： " << abs->personArray[i].m_Addr <<"\t"<< endl;
		}
		system("pause");
		system("cls");
	}
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1  通讯录  参数2  对比姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名了
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}


//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;

	int ret=isExist(abs, name);

	//如果ret==-1，则没有找到联系人
	//如果ret！=-1，则找到联系人
	if (ret !=-1)
	{
		for (int i = ret; i < abs->m_Size - 1; i++)
		{
			//数组前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "已成功删除" << endl;
	}
	else
	{
		cout << "没有找到该联系人" << endl;
	}

	system("pause");
	system("cls");
}


//查找联系人的信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;

	//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
	//调用检测的函数
	int ret=isExist(abs, name);
	//判断联系人是否存在
	if (ret != -1)//联系人存在
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex==1?"男":"女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << "\t"<<endl;
	}
	else  //联系人不存在
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}


//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;

	int ret=isExist(abs, name);

	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		int sex=0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误！请重新输入" << endl;
		}

		//年龄
		int age=0;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (0 < age && age < 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误！请重新输入" << endl;
		}

		//电话号码
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	//清屏
	system("pause");
	system("cls");
}


//清空联系人
void cleanPreson(Addressbooks* abs)
{
	int choose = 0;
	cout << "请确认您要清空联系人：" << endl;
	cout << "3 --- 确认！" << endl;
	cin >> choose;

	if (choose == 3)//判断用户是否真的想清空联系人
	{
		abs->m_Size = 0;
		cout << "通讯录已清空！" << endl;
		//按任意键清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "您未确认清空联系人!" << endl;

		//按任意键清屏
		system("pause");
		system("cls");
	}
}

void showMenu()
{	
	cout << "***************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

int main() {

	//创建真实的通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录人员个数
	abs.m_Size = 0;

	while (true)
	{
		int select = 0;
		showMenu();

		cin >> select;

		switch (select)
		{
			//1.添加联系人
		case 1:
			addPerson(&abs);//利用地址传递，可以修饰实参
			break;
			//2.显示联系人
		case 2:
			showPerson(&abs);//显示联系人的函数
			break;
			//3.删除联系人
		case 3:
			deletePerson(&abs);
			break;
			//4.查找联系人
		case 4:
			findPerson(&abs);
			break;
			//5.修改联系人
		case 5:
			modifyPerson(&abs);
			break;
			//6.清空int select = 0;
		case 6:
			cleanPreson(&abs);
			break;
			//0.退出通讯录
		case 0:
			system("pause");
			return 0;
			break;
		}
	}
	
	system("pause");
	return 0;
}
