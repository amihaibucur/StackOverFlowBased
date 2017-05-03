#include<iostream>
#include<ctime>
#include<algorithm>
#include<fstream>
using namespace std;

class Validations
{
public:
	static bool allAlpha(char* s1)
	{
		for (int i = 0; i < strlen(s1); i++)
		{
			if (!(s1[i] == ' ' || s1[i] == '-' || (s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= 'a' && s1[i] <= 'z')))
				return false;
		}
		return true;
	}
	static bool isCharacter(const char Character)
	{
		return ((Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z'));
	}
	static bool isCNPvalid(const char* cnp)
	{
		if (strlen(cnp) != 13) return false;
		for (int i = 0; i < strlen(cnp); i++)
		{
			if (!(cnp[i] >= '0' && cnp[i] <= '9'))
			{
				return false;
			}
		}
		return true;
	}
	static bool isPhoneNumberValid(char* phone)
	{
		if (strlen(phone) <= 5) return false;

		for (int i = 0; i < strlen(phone); i++)
		{
			if (!(((phone[i] >= '0') && (phone[i] <= '9')) || (phone[i] == '-') || (phone[i] == '+') || (phone[i] == ' ')))
			{
				return false;
			}

		}
		return true;
	}
	static bool isValidEmailAddress(const char * EmailAddress)
	{
		if (!EmailAddress)
			return 0;
		if (!Validations::isCharacter(EmailAddress[0]))
			return 0;
		int AtOffset = -1;
		int DotOffset = -1;
		unsigned int Length = strlen(EmailAddress);
		for (unsigned int i = 0; i < Length; i++)
		{
			if (EmailAddress[i] == '@')
				AtOffset = (int)i;
			else if (EmailAddress[i] == '.')
				DotOffset = (int)i;
		}
		if (AtOffset == -1 || DotOffset == -1)
			return 0;
		if (AtOffset > DotOffset)
			return 0;
		return !(DotOffset >= ((int)Length - 1));
	}
};

class User {
protected:
	const int id;
	static int nbOfUsers;
	char* username;
	char* password;
	char* fullname;
	char* email;
	char date[26];
	int type;

public:
	User() : id(nbOfUsers) {
		this->username = new char[strlen("N/A") + 1];
		strcpy(this->username, "N/A");

		this->password = new char[strlen("N/A") + 1];
		strcpy(this->password, "N/A");

		this->fullname = new char[strlen("N/A") + 1];
		strcpy(this->fullname, "N/A");

		this->email = new char[strlen("N/A") + 1];
		strcpy(this->email, "N/A");

		time_t now = time(0);
		strcpy(date, ctime(&now));
		type = 0;
		nbOfUsers++;
	}
	User(char* username, char* password, char* fullname, char* email, int type) : id(nbOfUsers) {

		if (username) {
			this->username = new char[strlen(username) + 1];
			strcpy(this->username, username);
		}
		else {
			this->username = new char[strlen("N/A") + 1];
			strcpy(this->username, "N/A");

		}

		if (password) {
			this->password = new char[strlen(password) + 1];
			strcpy(this->password, password);
		}
		else {
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}


		if (fullname) {
			this->fullname = new char[strlen(fullname) + 1];
			strcpy(this->fullname, fullname);
		}
		else {
			this->fullname = new char[strlen("N/A") + 1];
			strcpy(this->fullname, "N/A");
		}

		if (email) {
			this->email = new char[strlen(email) + 1];
			strcpy(this->email, email);
		}
		else{
			this->email = new char[strlen("N/A") + 1];
			strcpy(this->email, "N/A");
		}

		if (type == 0 || type == 1 || type == 2) {
			this->type = type;
		}
		else {
			this->type = 0;
		}

		time_t now = time(0);
		strcpy(date, ctime(&now));

		nbOfUsers++;
	}
	User(char* username, char* password, char* email) :id(nbOfUsers) {
		if (username != NULL) {
			this->username = new char[strlen(username) + 1];
			strcpy(this->username, username);
		}
		else{
			this->username = new char[strlen("N/A") + 1];
			strcpy(this->username, "N/A");
		}


		if (password != NULL){
			this->password = new char[strlen(password) + 1];
			strcpy(this->password, password);
		}
		else{
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}

		if (email != NULL){
			this->email = new char[strlen(email) + 1];
			strcpy(this->email, email);
		}
		else{
			this->email = new char[strlen("N/A") + 1];
			strcpy(this->email, "N/A");
		}

		this->fullname = new char[strlen("N/A") + 1];
		strcpy(this->fullname, "N/A");

		this->type = 0;

		time_t now = time(0);
		strcpy(this->date, ctime(&now));
		nbOfUsers++;
	}
	User(const User& u) :id(nbOfUsers) {
		if (u.username) {
			this->username = new char[strlen(u.username) + 1];
			strcpy(this->username, u.username);
		}
		else {
			this->username = new char[strlen("N/A") + 1];
			strcpy(this->username, "N/A");

		}

		if (u.password) {
			this->password = new char[strlen(u.password) + 1];
			strcpy(this->password, u.password);
		}
		else {
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}


		if (u.fullname) {
			this->fullname = new char[strlen(u.fullname) + 1];
			strcpy(this->fullname, u.fullname);
		}
		else {
			this->fullname = new char[strlen("N/A") + 1];
			strcpy(this->fullname, "N/A");
		}

		if (u.email) {
			this->email = new char[strlen(u.email) + 1];
			strcpy(this->email, u.email);
		}
		else{
			this->email = new char[strlen("N/A") + 1];
			strcpy(this->email, "N/A");
		}

		this->type = u.type;
		time_t now = time(0);
		strcpy(date, ctime(&now));

		nbOfUsers++;
	}
	User& operator=(const User& u) {
		if (this->username) {
			delete[] this->username;
		}
		if (u.username) {
			this->username = new char[strlen(u.username) + 1];
			strcpy(this->username, u.username);
		}
		else {
			this->username = new char[strlen("N/A") + 1];
			strcpy(this->username, "N/A");

		}

		if (this->password) {
			delete[] this->password;
		}

		if (u.password) {
			this->password = new char[strlen(u.password) + 1];
			strcpy(this->password, u.password);
		}
		else {
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}

		if (this->fullname) {
			delete[] this->fullname;
		}

		if (u.fullname) {
			this->fullname = new char[strlen(u.fullname) + 1];
			strcpy(this->fullname, u.fullname);
		}
		else {
			this->fullname = new char[strlen("N/A") + 1];
			strcpy(this->fullname, "N/A");
		}

		if (this->email) {
			delete[] this->email;
		}

		if (u.email) {
			this->email = new char[strlen(u.email) + 1];
			strcpy(this->email, u.email);
		}
		else{
			this->email = new char[strlen("N/A") + 1];
			strcpy(this->email, "N/A");
		}

		this->type = u.type;

		return *this;
	}
	~User() {
		if (this->username) {
			delete[] this->username;
		}
		if (this->password) {
			delete[] this->password;
		}
		if (this->fullname) {
			delete[] this->fullname;
		}
		if (this->email){
			delete[] this->email;
		}
	}

	int getId() {
		return this->id;
	}
	static int getNbOfUsers() {
		return nbOfUsers;
	}
	char* getUsername() {
		return this->username;
	}
	char* getPassword() {
		return this->password;
	}
	char* getFullname() {
		return this->fullname;
	}
	char* getEmail() {
		return this->email;
	}
	char* getDate() {
		return this->date;
	}
	int getType() {
		return this->type;
	}
	void setType(int type) {
		if (type == 1 || type == 0 || type == 2) {
			this->type = type;
		}
		else {
			throw("The type must be 0, 1, or 2.");
		}
	}
	void setUsername(char* username) {
		if (this->username) {
			delete[] this->username;
		}

		if (username) {
			this->username = new char[strlen(username) + 1];
			strcpy(this->username, username);
		}
		else {
			this->username = new char[strlen("N/A") + 1];
			strcpy(this->username, "N/A");
		}
	}
	void setPassword(char* password) {
		if (this->password != NULL){
			delete[] this->password;
		}
		if (password != NULL && strlen(password) >= 8){
			this->password = new char[strlen(password) + 1];
			strcpy(this->password, password);
		}
		else{
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}
	}
	void setFullName(char* fullname) {
		if (this->fullname != NULL) {
			delete[] this->fullname;
		}
		if (Validations::allAlpha(fullname) && strlen(fullname) >= 3) {
			this->fullname = new char[strlen(fullname) + 1];
			strcpy(this->fullname, fullname);
		}
		else {
			this->fullname = new char[strlen("N/A") + 1];
			strcpy(this->fullname, "N/A");
		}
	}
	void setEmail(char* email) {
		if (this->email != NULL){
			delete[] this->email;
		}

		if (email != NULL && Validations::isValidEmailAddress(email)) {
			this->email = new char[strlen(email) + 1];
			strcpy(this->email, email);
		}
		else{
			this->email = new char[strlen("N/A") + 1];
			strcpy(this->email, "N/A");
		}
	}
	void setDateAdmin(char* day, char* month, char* nbDay, char* hour, char* min, char* sec, char* year)
	{


		if ((strlen(day) == 3) && (strlen(month) == 3) && (atoi(nbDay) <= 31 && atoi(nbDay) >= 0)
			&& (atoi(hour) <= 24 && atoi(hour) >= 0) &&
			(atoi(min) <= 60 && atoi(min) >= 0) && (atoi(sec) <= 60
			&& atoi(nbDay) >= 0) && (atoi(year) <= 2017 && atoi(year) >= 0)){

			this->date[0] = day[0];
			this->date[1] = day[1];
			this->date[2] = day[2];
			this->date[3] = ' ';

			this->date[4] = month[0];
			this->date[5] = month[1];
			this->date[6] = month[2];
			this->date[7] = ' ';

			if (strlen(nbDay) == 1) {
				this->date[8] = '0';
				this->date[9] = nbDay[0];
			}
			else {
				this->date[8] = nbDay[0];
				this->date[9] = nbDay[1];
			}

			this->date[10] = ' ';

			if (strlen(hour) == 1) {
				this->date[11] = '0';
				this->date[12] = hour[0];
			}
			else {
				this->date[11] = hour[0];
				this->date[12] = hour[1];
			}


			this->date[13] = ':';

			if (strlen(min) == 1) {
				this->date[14] = '0';
				this->date[15] = min[0];
			}
			else {
				this->date[14] = min[0];
				this->date[15] = min[1];
			}

			this->date[16] = ':';

			if (strlen(sec) == 1) {
				this->date[17] = '0';
				this->date[18] = sec[0];
			}
			else {
				this->date[17] = sec[0];
				this->date[18] = sec[1];
			}

			this->date[19] = ' ';

			this->date[20] = year[0];
			this->date[21] = year[1];
			this->date[22] = year[2];
			this->date[23] = year[3];


			this->date[24] = '\n';
			this->date[25] = '\0';



		}
		else {
			strcpy(this->date, "N/A");
		}

	}
	void setDate(char* date){
		if (date) {
			strcpy(this->date, date);
		}
		else{
			time_t now = time(0);
			strcpy(this->date, ctime(&now));
		}
	}

	virtual void addToTxt() = 0;
};
int User::nbOfUsers = 0;


class SimpleUser : public User
{
protected:
	int reputation;
	char* badges;
	char* gender;
public:
	SimpleUser() : User() {
		this->gender = new char[strlen("N/A") + 1];
		strcpy(this->gender, "N/A");

		this->badges = new char[strlen("N/A") + 1];
		strcpy(this->badges, "N/A");

		this->reputation = 0;
	}
	SimpleUser(char* username, char* password, char* email, int reputation) : User(username, password, email){
		if (reputation > 0) {
			this->reputation = reputation;
		}
		else {
			this->reputation = 0;
		}

		this->gender = new char[strlen("N/A") + 1];
		strcpy(this->gender, "N/A");

		this->badges = new char[strlen("N/A") + 1];
		strcpy(this->badges, "N/A");

	}
	SimpleUser(char* username, char* password, char* email, char* fullname, int reputation, char* badges) : User(username, password, fullname, email, 0) {
		if (reputation > 0) {
			this->reputation = reputation;
		}
		else {
			this->reputation = 0;
		}

		if (badges) {
			this->badges = new char[strlen(badges) + 1];
			strcpy(this->badges, badges);
		}
		else {
			this->badges = new char[strlen("N/A") + 1];
			strcpy(this->badges, "N/A");
		}

		this->gender = new char[strlen("N/A") + 1];
		strcpy(this->gender, "N/A");
	}
	SimpleUser(char* username, char* password, char* email, char* fullname, int reputation, char* badges, char* gender)
		: User(username, password, fullname, email, 0) {
		if (reputation > 0) {
			this->reputation = reputation;
		}
		else {
			this->reputation = 0;
		}

		if (badges) {
			this->badges = new char[strlen(badges) + 1];
			strcpy(this->badges, badges);
		}
		else {
			this->badges = new char[strlen("N/A") + 1];
			strcpy(this->badges, "N/A");
		}
		if (gender) {
			this->gender = new char[strlen(gender) + 1];
			strcpy(this->gender, gender);
		}
		else {
			this->gender = new char[strlen("N/A") + 1];
			strcpy(this->gender, "N/A");
		}

	}
	SimpleUser(const SimpleUser& copy) : User(copy) {
		if (copy.reputation > 0) {
			this->reputation = copy.reputation;
		}
		else {
			this->reputation = 0;
		}

		if (copy.badges) {
			this->badges = new char[strlen(copy.badges) + 1];
			strcpy(this->badges, copy.badges);
		}
		else {
			this->badges = new char[strlen("N/A") + 1];
			strcpy(this->badges, "N/A");
		}

		if (copy.gender) {
			this->gender = new char[strlen(copy.gender) + 1];
			strcpy(this->gender, copy.gender);
		}
		else {
			this->gender = new char[strlen("N/A") + 1];
			strcpy(this->gender, "N/A");
		}

	}
	SimpleUser& operator=(const SimpleUser& copy) {
		if (this->username) {
			delete[] this->username;
		}
		if (copy.username) {
			this->username = new char[strlen(copy.username) + 1];
			strcpy(this->username, copy.username);
		}
		else {
			username = new char[strlen("N/A") + 1];
			strcpy(username, "N/A");

		}

		if (this->password) {
			delete[] this->password;
		}

		if (copy.password) {
			this->password = new char[strlen(copy.password) + 1];
			strcpy(this->password, copy.password);
		}
		else {
			this->password = new char[strlen("N/A") + 1];
			strcpy(password, "N/A");
		}

		if (this->fullname) {
			delete[] this->fullname;
		}

		if (copy.fullname) {
			this->fullname = new char[strlen(copy.fullname) + 1];
			strcpy(this->fullname, copy.fullname);
		}
		else {
			fullname = new char[strlen("N/A") + 1];
			strcpy(fullname, "N/A");
		}

		if (this->email) {
			delete[] this->email;
		}

		if (copy.email) {
			this->email = new char[strlen(copy.email) + 1];
			strcpy(this->email, copy.email);
		}
		else{
			this->email = new char[strlen("N/A") + 1];
			strcpy(this->email, "N/A");
		}

		this->reputation = copy.reputation;

		if (this->badges) {
			delete[] this->badges;
		}

		if (badges) {
			this->badges = new char[strlen(copy.badges) + 1];
			strcpy(this->badges, copy.badges);
		}
		else
		{
			this->badges = new char[strlen("N/A") + 1];
			strcpy(this->badges, "N/A");
		}

		if (this->gender) {
			delete[] this->gender;
		}

		if (copy.gender) {
			this->gender = new char[strlen(copy.gender) + 1];
			strcpy(this->gender, copy.gender);
		}
		else {
			this->gender = new char[strlen("N/A") + 1];
			strcpy(this->gender, "N/A");
		}

		this->type = copy.type;

		return *this;

	}
	~SimpleUser() {
		if (badges){
			delete[] badges;
		}

		if (this->gender) {
			delete[] this->gender;
		}

		nbOfUsers--;
	}

	int getReputation() {
		return this->reputation;
	}
	char* getBadges(){
		return this->badges;
	}
	char* getGender(){
		return this->gender;
	}
	void setReputation(int reputation) {
		if (reputation >= 0) {
			this->reputation = reputation;
		}
		else {
			throw("Reputation must be higher or equal to 0.");
		}
	}
	void setBadges(char* badges) {
		if (this->badges){
			delete[] this->badges;
		}
		if (badges){
			this->badges = new char[strlen(badges) + 1];
			strcpy(this->badges, badges);
		}
	}
	void setGender(char* gender) {
		if (this->gender){
			delete[] this->gender;
		}
		if (gender){
			this->gender = new char[strlen(gender) + 1];
			strcpy(this->gender, gender);
		}
	}

	static void SerializeSimpleUser(SimpleUser* vector, int size)
	{
		ofstream f("SimpleUsers.dat", ios::trunc | ios::binary);
		for (int i = 0; i < size; i++) {

			f.write((char*)&(vector[i].type), sizeof(int));

			char username1[50];
			strcpy(username1, vector[i].username);
			f.write(username1, 50);

			char password1[50];
			strcpy(password1, vector[i].password);
			f.write(password1, 50);

			char fullname1[50];
			strcpy(fullname1, vector[i].fullname);
			f.write(fullname1, 50);

			char email1[50];
			strcpy(email1, vector[i].email);
			f.write(email1, 50);

			f.write(vector[i].date, 26);

			f.write((char*)&(vector[i].reputation), sizeof(int));

			char badges1[50];
			strcpy(badges1, vector[i].badges);
			f.write(badges1, 50);

			char gender1[50];
			strcpy(gender1, vector[i].gender);
			f.write(gender1, 50);
		}
		f.close();
	}
	static void DeserializeSimpleUser(SimpleUser* &u, int& size) {
		ifstream f("SimpleUsers.dat", ios::in, ios::binary);
		int nb = 0;

		SimpleUser vector[100];
		if (f.is_open()){
			while (!(f.eof())) {

				f.read((char*)&(vector[nb].type), sizeof(int));
				char username1[50];
				f.read(username1, 50);
				vector[nb].setUsername(username1);


				char password1[50];
				f.read(password1, 50);
				vector[nb].setPassword(password1);


				char fullname1[50];
				f.read(fullname1, 50);
				vector[nb].setFullName(fullname1);

				char email1[50];
				f.read(email1, 50);
				vector[nb].setEmail(email1);

				f.read(vector[nb].date, 26);

				f.read((char*)&(vector[nb].reputation), sizeof(int));

				char badges1[50];
				f.read(badges1, 50);
				vector[nb].setBadges(badges1);

				char gender1[50];
				f.read(gender1, 50);
				vector[nb].setGender(gender1);
				nb++;
			}

			u = new SimpleUser[nb - 1];
			size = nb - 1;

			for (int i = 0; i < size; i++) {
				u[i] = vector[i];
			}
		}
		else {
			cout << endl << "The SimpleUsers.dat file does not exist!";
		}

		f.close();
	}
	void addToTxt()
	{
			ofstream fout;
			fout.open("UsersD.txt", ios::trunc);
			if (fout.is_open()){
				fout << endl << "Type:(0/1/2 User/Moderator/Administrator): " << this->type
					<< endl << "Username: " << this->username
					<< endl << "Fullname: " << this->fullname
					<< endl << "Email: " << this->email
					<< endl << "Fullname:" << this->fullname
					<< endl << "Date:" << this->date
					 << "Reputation:"<<this->reputation
					<< endl << "Badges:"<<this->badges
				    << endl << "Gender:"<<this->gender<<  endl << endl;
			}
			else {
				cout << "There is a problem with the file.";

			}
			fout.close();
		

	}
	static void addUser(SimpleUser& newq) {

		ofstream f("SimpleUsers.dat", ios::app | ios::binary);

		if (f.is_open()) {
			f.write((char*)&(newq.type), sizeof(int));

			char username1[50];
			strcpy(username1, newq.username);
			f.write(username1, 50);

			char password1[50];
			strcpy(password1, newq.password);
			f.write(password1, 50);

			char fullname1[50];
			strcpy(fullname1, newq.fullname);
			f.write(fullname1, 50);

			char email1[50];
			strcpy(email1, newq.email);
			f.write(email1, 50);

			f.write(newq.date, 26);

			f.write((char*)&(newq.reputation), sizeof(int));

			char badges1[50];
			strcpy(badges1, newq.badges);
			f.write(badges1, 50);

			char gender1[50];
			strcpy(gender1, newq.gender);
			f.write(gender1, 50);
		}
		else
		{
			cout << "The file cannot be opened.";
		}


		f.close();
	}
	static void ReadFromTxt() {
		int size;
		ifstream fin;
		fin.open("DataUsers.txt", ios::in);
		if (fin.is_open()) {
			fin >> size;
			cout << size;
			char buffer[100];
			fin.getline(buffer, 100);
			SimpleUser* users = new SimpleUser[size];
			for (int i = 0; i < size; i++){
				fin >> users[i];
			}

			ofstream fout;
			fout.open("SimpleUsers.dat");
			if (fout.is_open()){
				SimpleUser::SerializeSimpleUser(users, size);
				fout.close();
			}

			fin.close();

		}
		else {
			cout << "The file cannot be opened.";
		}

	}
	static void ShowFromBinary() {
		SimpleUser* lista;
		int size = 0;
		SimpleUser::DeserializeSimpleUser(lista, size);
		for (int i = 0; i < size; i++) {
			cout << lista[i];
		}

	}

	void addRep(int rep){
		this->reputation += rep;
	}

	friend ostream& operator<<(ostream&, SimpleUser&);
	friend istream& operator>>(istream&, SimpleUser&);
	friend ofstream& operator<<(ofstream&, SimpleUser&);
	friend ifstream& operator>>(ifstream&, SimpleUser&);

};
ifstream& operator>>(ifstream& fin, SimpleUser& cond) {
	fin >> cond.type;
	char aux[2];
	fin.getline(aux, 2);

	char linie[100];
	fin.getline(linie, 100);
	cond.setUsername(linie);

	fin.getline(linie, 100);
	cond.setPassword(linie);

	fin.getline(linie, 100);
	cond.setFullName(linie);

	fin.getline(linie, 100);
	cond.setEmail(linie);

	fin.getline(linie, 100);
	cond.setDate(linie);

	fin >> cond.reputation;
	fin.getline(linie, 100);

	fin.getline(linie, 100);
	cond.setBadges(linie);

	fin.getline(linie, 100);
	cond.setGender(linie);
	return fin;
}
ofstream& operator<<(ofstream& foutUser, SimpleUser& u)
{
	foutUser.open("DataUsers.txt", ios::app);
	if (foutUser)
	{
		foutUser << u.getType() << endl;
		foutUser << u.getUsername() << endl;
		foutUser << u.getPassword() << endl;
		foutUser << u.getFullname() << endl;
		foutUser << u.getEmail() << endl;
		foutUser << u.getDate();
		foutUser << u.getReputation() << endl;
		foutUser << u.getBadges() << endl;
		foutUser << u.getGender() << endl << endl;

	}
	foutUser.close();
	return foutUser;
}

ostream& operator<<(ostream& out, SimpleUser&  s1){
	out << endl << "Type:(0/1 User/Moderator)" << s1.getType()
		<< endl << "Username: " << s1.getUsername()
		<< endl << "Fullname: " << s1.getFullname()
		<< endl << "Email: " << s1.getEmail()
		<< endl << "Gender: " << s1.getGender()
		<< endl << "Reputation: " << s1.getReputation()
		<< endl << "Badges: " << s1.getBadges()
		<< endl << "Registered Date:" << s1.getDate();

	return out;
}
istream& operator>>(istream& in, SimpleUser& s1){
	int ok = 1;
	char username[30];
	char password[30];
	char fullname[50];
	char email[30];
	char gender[30];
	while (ok)
	{
		cout << "Username: ";
		fflush(stdin);
		in.getline(username, 30);
		if (strlen(username) < 5)
		{
			cout << endl << "The username must contain at least 5 characters." << endl;
		}
		else
		{
			if (s1.username != NULL)
			{
				delete[] s1.username;
			}

			s1.username = new char[strlen(username) + 1];
			strcpy(s1.username, username);
			ok = 0;

		}

	}
	ok = 1;
	while (ok)
	{
		cout << "Password: ";
		fflush(stdin);
		in.getline(password, 30);
		if (strlen(password) < 8)
		{
			cout << endl << "The password must contain at least 8 characters." << endl;
		}
		else
		{
			if (s1.password != NULL)
			{
				delete[] s1.password;
			}

			s1.password = new char[strlen(password) + 1];
			strcpy(s1.password, password);
			ok = 0;

		}

	}
	ok = 1;
	while (ok)
	{
		cout << "Fullname: ";
		fflush(stdin);
		in.getline(fullname, 30);
		if (!(Validations::allAlpha(fullname) && strlen(fullname) >= 3))
		{
			cout << endl << "Please insert the fullname correctly." << endl;
		}
		else
		{
			if (s1.fullname != NULL)
			{
				delete[] s1.fullname;
			}

			s1.fullname = new char[strlen(fullname) + 1];
			strcpy(s1.fullname, fullname);
			ok = 0;

		}

	}
	ok = 1;
	while (ok)
	{
		cout << "E-mail: ";
		fflush(stdin);
		in.getline(email, 30);
		if (!(Validations::isValidEmailAddress(email)))
		{
			cout << endl << "Please insert the e-mail correctly." << endl;
		}
		else
		{
			if (s1.email != NULL)
			{
				delete[] s1.email;
			}

			s1.email = new char[strlen(email) + 1];
			strcpy(s1.email, email);
			ok = 0;

		}

	}

	ok = 1;
	while (ok)
	{
		cout << "Gender ( 1- Male, 0- Female): ";
		fflush(stdin);
		int  g1;
		in >> g1;
		if (g1 != 0 && g1 != 1)
		{
			cout << endl << "Please insert 1 for male and 0 for female." << endl;
		}
		else
		{
			if (s1.gender != NULL)
			{
				delete[] s1.gender;
			}

			if (g1 == 0){
				s1.gender = new char[strlen("Female") + 1];
				strcpy(s1.gender, "Female");
				ok = 0;
			}
			else {
				s1.gender = new char[strlen("Male") + 1];
				strcpy(s1.gender, "Male");
				ok = 0;
			}

		}

	}

	return in;
}

class Moderator : public SimpleUser {
public:
	Moderator() : SimpleUser() {
		this->type = 1;
	}
	Moderator(char* username, char* password, char* email, int reputation) : SimpleUser(username, password, email, reputation) {
		this->type = 1;
	}
	Moderator(char* username, char* password, char* email, char* fullname, int reputation, char* badges) : Moderator(username, password, email, fullname, reputation, badges) {
		this->type = 1;
	}
	Moderator(char* username, char* password, char* email, char* fullname, int reputation, char* badges, char* gender) : SimpleUser(username, password, email, fullname, reputation, badges, gender) {
		this->type = 1;
	}
	Moderator(const Moderator& copy) : SimpleUser(copy) {
		this->type = 1;
	}
	Moderator& operator=(const Moderator& copy) {
		if (this->username) {
			delete[] this->username;
		}
		if (copy.username) {
			this->username = new char[strlen(copy.username) + 1];
			strcpy(this->username, copy.username);
		}
		else {
			username = new char[strlen("N/A") + 1];
			strcpy(username, "N/A");

		}

		if (this->password) {
			delete[] this->password;
		}

		if (copy.password) {
			this->password = new char[strlen(copy.password) + 1];
			strcpy(this->password, copy.password);
		}
		else {
			this->password = new char[strlen("N/A") + 1];
			strcpy(password, "N/A");
		}

		if (this->fullname) {
			delete[] this->fullname;
		}

		if (copy.fullname) {
			this->fullname = new char[strlen(copy.fullname) + 1];
			strcpy(this->fullname, copy.fullname);
		}
		else {
			fullname = new char[strlen("N/A") + 1];
			strcpy(fullname, "N/A");
		}

		if (this->email) {
			delete[] this->email;
		}

		if (copy.email) {
			this->email = new char[strlen(copy.email) + 1];
			strcpy(this->email, copy.email);
		}
		else{
			this->email = new char[strlen("N/A") + 1];
			strcpy(this->email, "N/A");
		}

		this->reputation = copy.reputation;

		if (this->badges) {
			delete[] this->badges;
		}

		if (badges) {
			this->badges = new char[strlen(copy.badges) + 1];
			strcpy(this->badges, copy.badges);
		}
		else
		{
			this->badges = new char[strlen("N/A") + 1];
			strcpy(this->badges, "N/A");
		}

		if (this->gender) {
			delete[] this->gender;
		}

		if (copy.gender) {
			this->gender = new char[strlen(copy.gender) + 1];
			strcpy(this->gender, copy.gender);
		}
		else {
			this->gender = new char[strlen("N/A") + 1];
			strcpy(this->gender, "N/A");
		}

		this->type = copy.type;

		return *this;
	}
	~Moderator(){
	};
public:
	static void addModerator(Moderator& newq) {

		ofstream f("SimpleUsers.dat", ios::app | ios::binary);

		if (f.is_open()) {
			f.seekp(ios::end);
			f.write((char*)&(newq.type), sizeof(int));

			char username1[50];
			strcpy(username1, newq.username);
			f.write(username1, 50);

			char password1[50];
			strcpy(password1, newq.password);
			f.write(password1, 50);

			char fullname1[50];
			strcpy(fullname1, newq.fullname);
			f.write(fullname1, 50);

			char email1[50];
			strcpy(email1, newq.email);
			f.write(email1, 50);

			f.write(newq.date, 26);

			f.write((char*)&(newq.reputation), sizeof(int));

			char badges1[50];
			strcpy(badges1, newq.badges);
			f.write(badges1, 50);

			char gender1[50];
			strcpy(gender1, newq.gender);
			f.write(gender1, 50);
		}
		else
		{
			cout << "The file cannot be opened.1";
		}


		f.close();
	}
	static void ShowFromBinary() {
		Moderator* lista;
		int size = 0;
		Moderator::DeserializeUsers(lista, size);
		for (int i = 0; i < size; i++) {
			cout << lista[i];
		}

	}
	static void SerializeModerator(Moderator* vector, int size)
	{
		ofstream f("SimpleUsers.dat", ios::out | ios::binary);
		for (int i = 0; i < size; i++) {

			f.write((char*)&(vector[i].type), sizeof(int));

			char username1[50];
			strcpy(username1, vector[i].username);
			f.write(username1, 50);

			char password1[50];
			strcpy(password1, vector[i].password);
			f.write(password1, 50);

			char fullname1[50];
			strcpy(fullname1, vector[i].fullname);
			f.write(fullname1, 50);

			char email1[50];
			strcpy(email1, vector[i].email);
			f.write(email1, 50);

			f.write(vector[i].date, 26);
			f.write((char*)&(vector[i].reputation), sizeof(int));

			char badges1[50];
			strcpy(badges1, vector[i].badges);
			f.write(badges1, 50);

			char gender1[50];
			strcpy(gender1, vector[i].gender);
			f.write(gender1, 50);
		}
		f.close();
	}
	static void DeserializeUsers(Moderator* &u, int& size) {
		ifstream f("SimpleUsers.dat", ios::in, ios::binary);
		int nb = 0;

		Moderator vector[100];
		if (f.is_open()) {
			while (!(f.eof())) {

				f.read((char*)&(vector[nb].type), sizeof(int));
				char username1[50];
				f.read(username1, 50);
				vector[nb].setUsername(username1);


				char password1[50];
				f.read(password1, 50);
				vector[nb].setPassword(password1);


				char fullname1[50];
				f.read(fullname1, 50);
				vector[nb].setFullName(fullname1);

				char email1[50];
				f.read(email1, 50);
				vector[nb].setEmail(email1);

				f.read(vector[nb].date, 26);

				f.read((char*)&(vector[nb].reputation), sizeof(int));

				char badges1[50];
				f.read(badges1, 50);
				vector[nb].setBadges(badges1);

				char gender1[50];
				f.read(gender1, 50);
				vector[nb].setGender(gender1);
				nb++;
			}

			u = new Moderator[nb - 1];
			size = nb - 1;

			for (int i = 0; i < size; i++) {
				u[i] = vector[i];
			}
		}
		else {
			cout << " The SimpleUsers.dat does not exist";
		}
		f.close();
	}
	void addToTxt()
	{
		ofstream f;
		f << *this;

	}
	static void Edit(char* username1){
		Moderator* x;
		int size = 0;
		int contor = 0;
		Moderator::DeserializeUsers(x, size);
		for (int i = 0; i < size; i++){
			if (!strcmp(x[i].getUsername(), username1)) {
				contor++;
				int decuser = 0;
				while (decuser != 7){
					cout << endl << endl << "Edit:";
					cout << endl << "1->Username";
					cout << endl << "2->Password";
					cout << endl << "3->Email";
					cout << endl << "4->Fullname";
					cout << endl << "5->Reputation";
					cout << endl << "6->Badges";
					cout << endl << "7->Back";
					cout << endl << "Your decision: ";
					cin >> decuser;
					if (decuser == 1){
						char username2[50];
						cout << endl << "Enter the new username:";
						fflush(stdin);
						cin.getline(username2, 50);
						x[i].setUsername(username2);
					}
					else if (decuser == 2){
						char password1[50];
						cout << endl << "Enter the new password:";
						fflush(stdin);
						cin.getline(password1, 50);
						x[i].setPassword(password1);
					}
					else if (decuser == 3){
						char email1[50];
						cout << endl << "Enter the new email adress:";
						fflush(stdin);
						cin.getline(email1, 50);
						x[i].setEmail(email1);
					}
					else if (decuser == 4){
						char fullname1[50];
						cout << endl << "Enter the new fullname:";
						fflush(stdin);
						cin.getline(fullname1, 50);
						x[i].setFullName(fullname1);
					}
					else if (decuser == 5){
						int rep;
						cout << endl << "Enter the new reputation:";

						cin >> rep;
						x[i].setReputation(rep);
					}
					else if (decuser == 6){
						char badges1[50];
						cout << endl << "Enter the new badges:";
						fflush(stdin);
						cin.getline(badges1, 50);
						x[i].setBadges(badges1);
					}
					else {
						decuser = 7;
					}

				}
			}
		}
		if (contor == 0) {
			cout << endl << "There is no user with that id.";
		}
		else
		{
			cout << "Succes!";
		}

		Moderator::SerializeModerator(x, size);
	}

};

class Administrator : public User {
private:
	static int nbOfAdministrators;
	char CNP[14];
	char* phoneNumber;

public:
	Administrator() : User() {
		strcpy(this->CNP, "9999999999999");
		this->phoneNumber = new char[strlen("N/A") + 1];
		strcpy(this->phoneNumber, "N/A");
		nbOfAdministrators++;
		this->type = 2;
	}
	Administrator(char* username, char* password, char* fullname, char* email, char* CNP, char* phoneNumber) : User(username, password, fullname, email, 2) {
		if (CNP){
			strcpy(this->CNP, CNP);
		}
		else {
			strcpy(this->CNP, "9999999999999");
		}

		if (phoneNumber) {
			this->phoneNumber = new char[strlen(phoneNumber) + 1];
			strcpy(this->phoneNumber, phoneNumber);
		}
		else {
			this->phoneNumber = new char[strlen("N/A") + 1];
			strcpy(this->phoneNumber, "N/A");
		}
		this->type = 2;
		nbOfAdministrators++;
	}
	Administrator(const Administrator& copy) : User(copy){
		if (copy.CNP){
			strcpy(this->CNP, copy.CNP);
		}
		else {
			strcpy(this->CNP, "9999999999999");
		}

		if (copy.phoneNumber) {
			this->phoneNumber = new char[strlen(copy.phoneNumber) + 1];
			strcpy(this->phoneNumber, copy.phoneNumber);
		}
		else {
			this->phoneNumber = new char[strlen("N/A") + 1];
			strcpy(this->phoneNumber, "N/A");
		}
		this->type = 2;
		nbOfAdministrators++;
	}
	Administrator& operator=(const Administrator& u) {
		if (this->username) {
			delete[] this->username;
		}
		if (u.username) {
			this->username = new char[strlen(u.username) + 1];
			strcpy(this->username, u.username);
		}
		else {
			this->username = new char[strlen("N/A") + 1];
			strcpy(this->username, "N/A");

		}

		if (this->password) {
			delete[] this->password;
		}

		if (u.password) {
			this->password = new char[strlen(u.password) + 1];
			strcpy(this->password, u.password);
		}
		else {
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}

		if (this->fullname) {
			delete[] this->fullname;
		}

		if (u.fullname) {
			this->fullname = new char[strlen(u.fullname) + 1];
			strcpy(this->fullname, u.fullname);
		}
		else {
			this->fullname = new char[strlen("N/A") + 1];
			strcpy(this->fullname, "N/A");
		}

		if (this->email) {
			delete[] this->email;
		}

		if (u.email) {
			this->email = new char[strlen(u.email) + 1];
			strcpy(this->email, u.email);
		}
		else{
			this->email = new char[strlen("N/A") + 1];
			strcpy(this->email, "N/A");
		}

		this->type = u.type;

		if (this->phoneNumber) {
			delete[] this->phoneNumber;
		}
		if (u.phoneNumber) {
			this->phoneNumber = new char[strlen(u.phoneNumber) + 1];
			strcpy(this->phoneNumber, u.phoneNumber);
		}
		else {
			this->phoneNumber = new char[strlen("N/A") + 1];
			strcpy(this->phoneNumber, "N/A");
		}

		if (strlen(u.CNP) == 13){
			strcpy(this->CNP, u.CNP);
		}
		else {
			strcpy(this->CNP, "9999999999999");
		}


		return (*this);
	}
	~Administrator() {
		if (this->phoneNumber) {
			delete[] this->phoneNumber;
		}
	}

	char* getCNP() {
		return this->CNP;
	}
	char* getPhoneNumber() {
		return this->phoneNumber;
	}
	void setPhoneNumber(char* phoneNumber) {
		if (this->phoneNumber){
			delete[] this->phoneNumber;
		}

		if (phoneNumber) {
			this->phoneNumber = new char[strlen(phoneNumber) + 1];
			strcpy(this->phoneNumber, phoneNumber);
		}
		else {
			this->phoneNumber = new char[strlen("N/A") + 1];
			strcpy(this->phoneNumber, "N/A");
		}
	}
	static void SerializeAdministrator(Administrator* vector, int size) {
		ofstream f("Administrators.dat", ios::out | ios::binary);
		for (int i = 0; i < size; i++) {
			f.write((char*)&(vector[i].type), sizeof(int));

			char username1[50];
			strcpy(username1, vector[i].username);
			f.write(username1, 50);

			char password1[50];
			strcpy(password1, vector[i].password);
			f.write(password1, 50);

			char fullname1[50];
			strcpy(fullname1, vector[i].fullname);
			f.write(fullname1, 50);

			char email1[50];
			strcpy(email1, vector[i].email);
			f.write(email1, 50);

			f.write(vector[i].date, 26);
			f.write(vector[i].CNP, 14);

			char phoneNumber1[50];
			strcpy(phoneNumber1, vector[i].phoneNumber);
			f.write(phoneNumber1, 50);

		}

		f.close();
	}
	static void addAdministrator(Administrator& vector) {
		ofstream f("Administrators.dat", ios::app | ios::binary);

		if (f.is_open()){
			f.write((char*)&(vector.type), sizeof(int));

			char username1[50];
			strcpy(username1, vector.username);
			f.write(username1, 50);

			char password1[50];
			strcpy(password1, vector.password);
			f.write(password1, 50);

			char fullname1[50];
			strcpy(fullname1, vector.fullname);
			f.write(fullname1, 50);

			char email1[50];
			strcpy(email1, vector.email);
			f.write(email1, 50);

			f.write(vector.date, 26);
			f.write(vector.CNP, 14);

			char phoneNumber1[50];
			strcpy(phoneNumber1, vector.phoneNumber);
			f.write(phoneNumber1, 50);
		}
		else {
			cout << "The file cannot be opened.";
		}

		f.close();

	}
	static void DeserializeAdministrator(Administrator* &u, int& size){
		ifstream f("Administrators.dat", ios::in, ios::binary);
		int nb = 0;

		Administrator vector[100];
		if (f.is_open()){
			while (!(f.eof())) {

				f.read((char*)&(vector[nb].type), sizeof(int));
				char username1[50];
				f.read(username1, 50);
				vector[nb].setUsername(username1);


				char password1[50];
				f.read(password1, 50);
				vector[nb].setPassword(password1);


				char fullname1[50];
				f.read(fullname1, 50);
				vector[nb].setFullName(fullname1);

				char email1[50];
				f.read(email1, 50);
				vector[nb].setEmail(email1);

				f.read(vector[nb].date, 26);

				f.read(vector[nb].CNP, 14);

				char phoneNumber1[50];
				f.read(phoneNumber1, 50);
				vector[nb].setPhoneNumber(phoneNumber1);

				nb++;
			}

			u = new Administrator[nb - 1];
			size = nb - 1;

			for (int i = 0; i < size; i++) {
				u[i] = vector[i];
			}
		}
		else {
			cout << "The Administrators.dat file does not exist!";
		}
		f.close();
	}

	void addToTxt(){
		ofstream fout;
		fout.open("Administrators.txt", ios::trunc);
		if (fout.is_open()){
			fout << endl << "Type:(0/1/2 User/Moderator/Administrator): " << this->type
				<< endl << "Username: " << this->username
				<< endl << "Fullname: " << this->fullname
				<< endl << "Email: " << this->email
				<< endl << "CNP: " << this->CNP
				<< endl << "PhoneNumber: " << this->phoneNumber << endl;
		}
		else {
			cout << "There is a problem with the file.";

		}
		fout.close();
	};
	friend ostream& operator<<(ostream&, Administrator&);
	friend istream& operator>>(istream&, Administrator&);
	friend ofstream& operator<<(ofstream&, Administrator&);
}; 
ofstream& operator<<(ofstream& fout, Administrator& s1) {
	fout.open("AdministratorsRaw.txt", ios::app);
	if (fout.is_open()){
		fout << endl<< s1.getType()
			<< endl << s1.getUsername()
			<< endl << s1.getFullname()
			<< endl << s1.getEmail()
			<< endl << s1.getCNP()
			<< endl << s1.getPhoneNumber() << endl;
	}
	else {
		cout << "There is a problem with the file.";
			
	}
	fout.close();
	return fout;
}

ostream& operator<<(ostream& out, Administrator&  s1){
	out << endl << "Type:(0/1/2 User/Moderator/Administrator): " << s1.getType()
		<< endl << "Username: " << s1.getUsername()
		<< endl << "Fullname: " << s1.getFullname()
		<< endl << "Email: " << s1.getEmail()
		<< endl << "CNP: " << s1.getCNP()
		<< endl << "PhoneNumber: " << s1.getPhoneNumber() << endl;


	return out;
}

int Administrator::nbOfAdministrators = 0;
istream& operator>>(istream& in, Administrator& s1){
	int ok = 1;
	char username[50];
	char password[50];
	char fullname[50];
	char email[50];
	char phoneNumber[50];

	while (ok)
	{
		cout << "Username: ";
		fflush(stdin);
		in.getline(username, 50);
		if (strlen(username) < 5)
		{
			cout << endl << "The username must contain at least 5 characters." << endl;
		}
		else
		{
			s1.setUsername(username);
			ok = 0;

		}

	}
	ok = 1;
	while (ok)
	{
		cout << "Password: ";
		fflush(stdin);
		in.getline(password, 50);
		if (strlen(password) < 8)
		{
			cout << endl << "The password must contain at least 8 characters." << endl;
		}
		else
		{
			s1.setPassword(password);
			ok = 0;

		}

	}
	ok = 1;
	while (ok)
	{
		cout << "Fullname: ";
		fflush(stdin);
		in.getline(fullname, 50);
		if (!(Validations::allAlpha(fullname) && strlen(fullname) >= 3))
		{
			cout << endl << "Please insert the fullname correctly." << endl;
		}
		else
		{
			s1.setFullName(fullname);
			ok = 0;

		}

	}
	ok = 1;
	while (ok)
	{
		cout << "E-mail: ";
		fflush(stdin);
		in.getline(email, 50);
		if (!(Validations::isValidEmailAddress(email)))
		{
			cout << endl << "Please insert the e-mail correctly." << endl;
		}
		else
		{
			s1.setEmail(email);
			ok = 0;

		}

	}

	ok = 1;

	while (ok)
	{

		cout << "Enter your phone number: ";
		in.getline(phoneNumber, 50);

		if (Validations::isPhoneNumberValid(phoneNumber))
		{
			s1.setPhoneNumber(phoneNumber);
			ok = 0;
		}
		else
		{
			cout << endl << "Please enter a valid phone number." << endl;
		}
	}

	char CNP[14];
	ok = 1;
	while (ok)
	{
		cout << "Enter your CNP: ";
		fflush(stdin);
		in.getline(CNP, 14);
		if (Validations::isCNPvalid(CNP))
		{
			strcpy(s1.CNP, CNP);
			ok = 0;
		}
		else
		{
			cout << endl << "Please enter a valid CNP.";
		}
	}



	return in;
}




class Answer {
private:
	SimpleUser u;
	int votes;
	char dateA[26];
	char* answer;
	static int nbOfAnswers;
	int questionAnsweredId;
	int id;

public:


	Answer(){
		SimpleUser copy;
		this->u = copy;

		this->answer = new char[strlen("N/A") + 1];
		strcpy(this->answer, "N/A");

		time_t now = time(0);
		strcpy(this->dateA, ctime(&now));

		this->votes = 0;
		questionAnsweredId = 0;
		nbOfAnswers++;
	}
	Answer(SimpleUser& u, char* answer, int questionAnsweredId){
		this->u = u;
		if (answer) {
			this->answer = new char[strlen(answer) + 1];
			strcpy(this->answer, answer);
		}
		else {
			this->answer = new char[strlen("N/A") + 1];
			strcpy(this->answer, "N/A");
		}

		this->votes = 0;
		if (questionAnsweredId >= 0) {
			this->questionAnsweredId = questionAnsweredId;
		}
		else {
			throw"You must enter the questionAnsweredId too.";
		}

		time_t now = time(0);
		strcpy(this->dateA, ctime(&now));

		nbOfAnswers++;

	}
	Answer(SimpleUser& x, char* answer, int votes, int questionAnsweredId){
		this->u = x;

		if (answer != NULL){

			this->answer = new char[strlen(answer) + 1];
			strcpy(this->answer, answer);
		}
		else
		{
			this->answer = new char[strlen("N/A") + 1];
			strcpy(this->answer, "N/A");
		}
		if (questionAnsweredId >= 0) {
			this->questionAnsweredId = questionAnsweredId;
		}
		else {
			throw"You must enter the questionAnsweredId too.";
		}

		this->votes = votes;

		time_t now = time(0);
		strcpy(this->dateA, ctime(&now));

		nbOfAnswers++;
	}
	Answer(const Answer& copy)
	{
		this->u = copy.u;

		if (copy.answer != NULL) {

			this->answer = new char[strlen(copy.answer) + 1];
			strcpy(this->answer, copy.answer);
		}
		else {
			this->answer = new char[strlen("N/A") + 1];
			strcpy(this->answer, "N/A");
		}
		if (copy.questionAnsweredId >= 0) {
			this->questionAnsweredId = copy.questionAnsweredId;
		}
		else {
			throw"You must enter the questionAnsweredId too.";
		}

		this->votes = copy.votes;


		time_t now = time(0);
		strcpy(this->dateA, ctime(&now));

		nbOfAnswers++;

	}
	Answer& operator=(const Answer& copy)
	{
		this->u = copy.u;
		this->id = copy.id;


		if (this->answer != NULL)
		{
			delete[] this->answer;
		}

		if (copy.answer != NULL)
		{

			this->answer = new char[strlen(copy.answer) + 1];
			strcpy(this->answer, copy.answer);
		}
		else
		{
			this->answer = new char[strlen("N/A") + 1];
			strcpy(this->answer, "N/A");
		}

		if (copy.questionAnsweredId >= 0) {
			this->questionAnsweredId = copy.questionAnsweredId;
		}
		else {
			throw"You must enter the questionAnsweredId too.";
		}

		this->votes = copy.votes;


		time_t now = time(0);
		strcpy(this->dateA, ctime(&now));
		return *this;
	}
	~Answer()
	{
		if (this->answer != NULL)
		{
			delete[] this->answer;
		}

		nbOfAnswers--;

	}
	SimpleUser getUser() {
		return this->u;
	}
	char* getUsername() {
		return this->u.getUsername();
	}
	int getVotes() {
		return votes;
	}
	char* getDate() {
		return this->dateA;
	}
	char* getAnswer() {
		return this->answer;
	}
	static int  getNbOfAnswers() {
		return nbOfAnswers;
	}
	int getId() {
		return this->id;
	}
	int getQuestionAnsweredId(){
		return this->questionAnsweredId;
	}
	void setId(int id) {
		this->id = id;
	}
	void setVotes(int votes) {
		if (votes > 0) {
			this->votes = votes;
		}
		else {
			this->votes = 0;
		}
	}
	void setDate(char* date) {
		if (date) {
			strcpy(this->dateA, date);
		}
		else {
			time_t now = time(0);
			strcpy(this->dateA, ctime(&now));
		}
	}
	void setAnswer(char* answer) {
		if (this->answer != NULL)
		{
			delete[] this->answer;

		}

		if (answer != NULL)
		{

			this->answer = new char[strlen(answer) + 1];
			strcpy(this->answer, answer);
		}
		else
		{
			this->answer = new char[strlen("N/A") + 1];
			strcpy(this->answer, "N/A");
		}
	}
	void setQuestionAnsweredId(int questionid){
		if (questionid >= 0) {
			this->questionAnsweredId = questionid;
		}
		else {
			throw("Incorrect question id");
		}
	}

	static void ReadFromTxt() {
		int size;
		ifstream fin;
		fin.open("AnswersText.txt", ios::in);
		if (fin.is_open()) {
			fin >> size;
			cout << size;
			char buffer[100];
			fin.getline(buffer, 100);
			Answer* answers = new Answer[size];
			for (int i = 0; i < size; i++){
				fin >> answers[i];
			}

			ofstream fout;
			fout.open("Answers.dat");
			if (fout.is_open()){
				Answer::SerializeAnswer(answers, size);
				fout.close();
			}

			fin.close();

		}
		else {
			cout << "The file cannot be opened.";
		}

	}
	static void ShowFromBinary() {
		Answer* lista;
		int size = 0;
		Answer::DeserializeAnswer(lista, size);
		for (int i = 0; i < size; i++) {
			cout << lista[i];
		}

	}
	static void SerializeAnswer(Answer* vector, int size)
	{
		ofstream f("Answers.dat", ios::trunc | ios::binary);
		for (int i = 0; i < size; i++) {

			char username1[50];
			strcpy(username1, vector[i].u.getUsername());
			f.write(username1, 50);
			f.write((char*)&(vector[i].id), sizeof(int));
			f.write((char*)&(vector[i].questionAnsweredId), sizeof(int));

			char answer1[500];
			strcpy(answer1, vector[i].answer);
			f.write(answer1, 500);

			f.write((char*)&(vector[i].votes), sizeof(int));

			char dateA1[50];
			strcpy(dateA1, vector[i].dateA);
			f.write(dateA1, 50);

		}
		f.close();
	}
	static void addAnswer(Answer vector)
	{
		ofstream f("Answers.dat", ios::app | ios::binary);


		if (f.is_open()) {
			f.seekp(ios::end);
			char username1[50];
			strcpy(username1, vector.u.getUsername());
			f.write(username1, 50);
			f.write((char*)&(vector.id), sizeof(int));
			f.write((char*)&(vector.questionAnsweredId), sizeof(int));

			char answer1[500];
			strcpy(answer1, vector.answer);
			f.write(answer1, 500);

			f.write((char*)&(vector.votes), sizeof(int));

			char dateA1[50];
			strcpy(dateA1, vector.dateA);
			f.write(dateA1, 50);
		}
		else {
			cout << "The file cannot be opened.";
		}


		f.close();
	}
	void setU(SimpleUser& copy){
		this->u = copy;
	}

	static void EditAnswer(int id){
		Answer* lista;
		int size = 0;

		char text[500];
		cout << "Enter the modified question.";
		fflush(stdin);
		cin.getline(text, 500);

		Answer::DeserializeAnswer(lista, size);
		for (int i = 0; i < size; i++) {
			if (lista[i].getId() == id) {
				lista[i].setAnswer(text);
			}
		}
		Answer::SerializeAnswer(lista, size);

		cout << "The answer has been edited.";
	}
	static void DeserializeAnswer(Answer* &u, int& size) {
		ifstream f("Answers.dat", ios::in, ios::binary);
		int nb = 0;

		Answer vector[100];
		if (f.is_open()){
			while (!(f.eof())) {

				char username1[50];
				f.read(username1, 50);
				vector[nb].u.setUsername(username1);
				f.read((char*)&(vector[nb].id), sizeof(int));
				f.read((char*)&(vector[nb].questionAnsweredId), sizeof(int));

				char answer1[500];
				f.read(answer1, 500);
				vector[nb].setAnswer(answer1);

				f.read((char*)&(vector[nb].votes), sizeof(int));

				char dateA1[50];
				f.read(dateA1, 50);
				vector[nb].setDate(dateA1);

				nb++;
			}

			u = new Answer[nb - 1];
			size = nb - 1;

			for (int i = 0; i < size; i++) {
				u[i] = vector[i];
			}

			f.close();
		}
		else {
			cout << "The Answers.dat file does not exist";
		}
	}
	void addToTxt()
	{
		ofstream f;
		f << *this;

	}
	static int getNbOfAnswersTxt() {
		fstream f;
		f.open("nbOfAns.txt", ios::in);
		if (f.is_open()){

			int x;
			f >> x;
			return x;

			f.close();
		}
		else{
			ofstream x1;
			x1.open("nbOfAns.txt", ios::out);
			x1 << "0";
			x1.close();
			return 0;
		}
	}
	static void setNbOfAnswersTxt(int nbOfAns){
		ofstream f;
		f.open("nbOfAns.txt", ios::out);
		if (f.is_open()) {
			f << nbOfAns;
			f.close();
		}
		else {
			cout << "The file can not be opened";
		}
	}
	static void Add1Vote(int id){
		Answer* lista;
		int size = 0;
		Answer::DeserializeAnswer(lista, size);
		for (int i = 0; i < size; i++) {
			if (lista[i].getId() == id) {
				lista[i].votes++;

				SimpleUser* listau;
				int sizeu = 0;
				SimpleUser::DeserializeSimpleUser(listau, sizeu);
				for (int j = 0; j < sizeu; j++) {
					if (!strcmp(lista[i].getUsername(), listau[j].getUsername())){
						listau[j].addRep(10);
					}
				}
				SimpleUser::SerializeSimpleUser(listau, sizeu);

			}
		}
		Answer::SerializeAnswer(lista, size);



	}

	static void ShowAnswersIdQuestion(int questionid){
		if (questionid >= 0){
			Answer* lista;
			int size = 0;
			int count = 0;

			Answer::DeserializeAnswer(lista, size);

			for (int i = 0; i < size; i++){
				if (lista[i].getQuestionAnsweredId() == questionid){
					cout << lista[i];
					count++;
				}
			}
			if (count == 0){
				cout << "No answers for that question.";
			}
		}
	}

	friend ostream& operator<<(ostream&, Answer&);
	friend istream& operator>>(istream&, Answer&);
	friend ofstream& operator<<(ofstream&, Answer&);
	friend ifstream& operator>>(ifstream&, Answer&);

};

ostream& operator<<(ostream& out, Answer& anso){
	out << endl << "Answer id: " << anso.getId();
	out << endl << "Username: " << anso.u.getUsername();
	out << endl << "Question Answered Id" << anso.questionAnsweredId;
	out << endl << "Answer" << anso.getAnswer();
	out << endl << "Votes" << anso.getVotes();
	out << endl << "Date" << anso.getDate();
	return out;

}
ofstream& operator<<(ofstream& fout, Answer& an) {
	fout.open("AnswersText.txt", ios::app);
	if (fout) {
		fout << endl << an.u.getUsername();
		fout << endl << an.questionAnsweredId;
		fout << endl << an.getAnswer();
		fout << endl << an.getVotes();
		fout << endl << an.getDate();
	}
	else {
		cout << "The file can not be opened.";
	}
	fout.close();
	return fout;


}
ifstream& operator>>(ifstream& fin, Answer& ann) {
	char linie[100];
	char linie2[500];
	char aux[2];
	fin.getline(aux, 2);
	fin.getline(linie, 100);
	ann.u.setUsername(linie);

	fin >> ann.questionAnsweredId;
	fin.getline(aux, 2);

	fin.getline(linie, 500);
	ann.setAnswer(linie);

	fin >> ann.votes;

	fin.getline(linie, 100);
	ann.setDate(linie);

	return fin;
}
istream& operator>>(istream& in, Answer& a)
{
	cout << endl << "What's the question you want to answer?";
	in >> a.questionAnsweredId;
	cout << endl << "Enter the answer: ";
	char answer[200]; fflush(stdin);
	in.getline(answer, 200);

	if (a.answer != NULL)
	{
		delete[] a.answer;
	}

	if (answer != NULL)
	{
		a.answer = new char[strlen(answer) + 1];
		strcpy(a.answer, answer);
	}
	else
	{
		a.answer = new char[strlen("N/A") + 1];
		strcpy(a.answer, "N/A");
	}

	return in;
}


int Answer::nbOfAnswers = 0;

class Question
{
private:
	SimpleUser u;
	char* QuestionArea;
	char* question;
	char dateQ[26];
	int id;
	int votes;
	static int nbOfQuestions;
	int ok;
	int active;

public:

	void setId(int id) {
		this->id = id;
	}
	void setU(SimpleUser& copy) {
		this->u = copy;
	}
	SimpleUser& getU()
	{
		return this->u;
	}
	Question()
	{
		SimpleUser u1;
		u = u1;
		this->question = new char[strlen("N/A") + 1];
		strcpy(this->question, "N/A");

		this->QuestionArea = new char[strlen("N/A") + 1];
		strcpy(this->QuestionArea, "N/A");

		this->votes = 0;

		time_t now = time(0);
		strcpy(dateQ, ctime(&now));

		active = 1;

		nbOfQuestions++;
	}
	Question(char* username)
	{
		if (username){
			this->u.setUsername(username);
		}
		else {
			throw("The username must not be empty.");
		}
		this->question = new char[strlen("N/A") + 1];
		strcpy(this->question, "N/A");

		this->QuestionArea = new char[strlen("N/A") + 1];
		strcpy(this->QuestionArea, "N/A");


		this->votes = 0;
		this->active = 1;

		time_t now = time(0);
		strcpy(dateQ, ctime(&now));

		nbOfQuestions++;
	}
	Question(SimpleUser& u1)
	{
		this->u = u1;
		this->question = new char[strlen("N/A") + 1];
		strcpy(this->question, "N/A");

		this->QuestionArea = new char[strlen("N/A") + 1];
		strcpy(this->QuestionArea, "N/A");


		this->votes = 0;
		this->active = 0;


		time_t now = time(0);
		strcpy(dateQ, ctime(&now));

		nbOfQuestions++;
	}
	Question(SimpleUser& u1, char* QuestionArea, char* question, int votes)
	{
		u = u1;
		if (QuestionArea != NULL)
		{

			this->QuestionArea = new char[strlen(QuestionArea) + 1];
			strcpy(this->QuestionArea, QuestionArea);
		}
		else
		{
			this->QuestionArea = new char[strlen("N/A") + 1];
			strcpy(this->QuestionArea, "N/A");
		}

		if (question != NULL)
		{

			this->question = new char[strlen(question) + 1];
			strcpy(this->question, question);
		}
		else
		{
			this->question = new char[strlen("N/A") + 1];
			strcpy(this->question, "N/A");
		}


		this->votes = votes;
		this->active = 1;

		time_t now = time(0);
		strcpy(dateQ, ctime(&now));

		nbOfQuestions++;
	}
	Question(SimpleUser& u1, char* QuestionArea, char* question)
	{

		u = u1;
		if (QuestionArea != NULL)
		{

			this->QuestionArea = new char[strlen(QuestionArea) + 1];
			strcpy(this->QuestionArea, QuestionArea);
		}
		else
		{
			this->QuestionArea = new char[strlen("N/A") + 1];
			strcpy(this->QuestionArea, "N/A");
		}

		if (question != NULL)
		{

			this->question = new char[strlen(question) + 1];
			strcpy(this->question, question);
		}
		else
		{
			this->question = new char[strlen("N/A") + 1];
			strcpy(this->question, "N/A");
		}

		this->active = 1;
		this->votes = 0;
		time_t now = time(0);
		strcpy(dateQ, ctime(&now));

		nbOfQuestions++;
	}
	Question(const Question& copy)
	{
		this->u = copy.u;

		if (copy.QuestionArea != NULL)
		{

			this->QuestionArea = new char[strlen(copy.QuestionArea) + 1];
			strcpy(this->QuestionArea, copy.QuestionArea);
		}
		else
		{
			this->QuestionArea = new char[strlen("N/A") + 1];
			strcpy(this->QuestionArea, "N/A");
		}

		if (copy.question != NULL)
		{

			this->question = new char[strlen(copy.question) + 1];
			strcpy(this->question, copy.question);
		}
		else
		{
			this->question = new char[strlen("N/A") + 1];
			strcpy(this->question, "N/A");
		}

		this->active = 1;
		this->votes = copy.votes;


		time_t now = time(0);
		strcpy(dateQ, ctime(&now));

		nbOfQuestions++;



	}
	Question& operator=(const Question& copy)
	{
		this->u = copy.u;
		this->id = copy.id;

		if (this->QuestionArea != NULL)
		{
			delete[] this->QuestionArea;
		}

		if (copy.QuestionArea != NULL)
		{

			this->QuestionArea = new char[strlen(copy.QuestionArea) + 1];
			strcpy(this->QuestionArea, copy.QuestionArea);
		}
		else
		{
			this->QuestionArea = new char[strlen("N/A") + 1];
			strcpy(this->QuestionArea, "N/A");
		}

		if (this->question != NULL)
		{
			delete[] this->question;
		}

		if (copy.question != NULL)
		{

			this->question = new char[strlen(copy.question) + 1];
			strcpy(this->question, copy.question);
		}
		else
		{
			this->question = new char[strlen("N/A") + 1];
			strcpy(this->question, "N/A");
		}


		this->votes = copy.votes;

		this->active = copy.active;


		strcpy(this->dateQ, copy.dateQ);


		return *this;
	}
	~Question()
	{
		if (this->QuestionArea != NULL)
		{
			delete[] this->QuestionArea;
		}

		if (this->question != NULL)
		{
			delete[] this->question;
		}

		nbOfQuestions--;
	}
	char* getQuestionArea()
	{
		return this->QuestionArea;
	}
	char* getQuestion()
	{
		return this->question;
	}
	char * getDateQ()
	{
		return this->dateQ;
	}
	int getVotes()
	{
		return this->votes;
	}
	int getActive() {
		return this->active;
	}
	int getId(){
		return this->id;
	}
	char* getUsername(){
		return this->u.getUsername();
	}
	void setQuestionArea(char* questionArea) {
		if (this->QuestionArea) {
			delete[] this->QuestionArea;
		}
		if (questionArea) {
			this->QuestionArea = new char[strlen(questionArea) + 1];
			strcpy(this->QuestionArea, questionArea);
		}
		else {
			throw("The questionArea must not be empty!");;
		}
	}
	void setQuestion(char* question) {
		if (this->question) {
			delete[] this->question;
		}
		if (question) {
			this->question = new char[strlen(question) + 1];
			strcpy(this->question, question);
		}
		else {
			throw("The question must not be empty!");;
		}
	}
	void setDateQ(char* dateQ) {

		if (dateQ) {

			strcpy(this->dateQ, dateQ);
		}
		else {
			throw("The date must not be empty!");;
		}
	}
	void setVotes(int votes) {
		if (votes > 0) {
			this->votes = votes;
		}
		else {
			this->votes = 0;
		}
	}
	void setActive(int active) {
		if (active == 1) {
			this->active = active;
		}
		else {
			this->active = 0;
		}
	}
	void addToTxt()
	{
		ofstream f;
		f << *this;

	}

	void operator++(){
		this->votes++;
	}
	static void EditQuestion(int id){
		Question* lista;
		int size = 0;

		char text[500];
		cout << "Enter the modified question.";
		fflush(stdin);
		cin.getline(text, 500);

		Question::DeserializeQuestion(lista, size);
		for (int i = 0; i < size; i++) {
			if (lista[i].getId() == id) {
				lista[i].setQuestion(text);
			}
		}
		Question::SerializeQuestion(lista, size);

		cout << "The question has been edited.";
	}
	static void DeleteQuestion(int id){
		Question* lista;
		int size = 0;

		Question::DeserializeQuestion(lista, size);
		for (int i = 0; i < size; i++) {
			if (lista[i].getId() == id) {
				lista[i].setActive(0);
			}
		}
		Question::SerializeQuestion(lista, size);

	}
	static void SearchQueston(char* questionArea) {
		Question* lista;
		int size = 0;
		int contor = 0;
		Question::DeserializeQuestion(lista, size);
		for (int i = 0; i < size; i++)
		if (!(strcmp(lista[i].getQuestionArea(), questionArea)) && lista[i].getActive() == 1) {
			contor++;
			cout << lista[i];
		}

		if (contor == 0) {
			cout << endl << "No questions with that question area" << endl;
		}

	}
	static void SerializeQuestion(Question* vector, int size)
	{
		ofstream f("Questions.dat", ios::trunc | ios::binary);
		for (int i = 0; i < size; i++) {
			f.write((char*)&(vector[i].id), sizeof(int));
			f.write((char*)&(vector[i].active), sizeof(int));

			char username1[50];
			strcpy(username1, vector[i].u.getUsername());
			f.write(username1, 50);

			char questionArea1[50];
			strcpy(questionArea1, vector[i].getQuestionArea());
			f.write(questionArea1, 50);

			char question1[500];
			strcpy(question1, vector[i].getQuestion());
			f.write(question1, 500);

			f.write((char*)&(vector[i].votes), sizeof(int));
			char dateQ1[50];
			strcpy(dateQ1, vector[i].dateQ);
			f.write(dateQ1, 50);

		}
		f.close();
	}
	static void addQuestion(Question& newq) {

		ofstream f("Questions.dat", ios::app | ios::binary);

		if (f.is_open()) {
			f.seekp(ios::end);
			f.write((char*)&(newq.id), sizeof(int));
			f.write((char*)&(newq.active), sizeof(int));

			char username1[50];
			strcpy(username1, newq.u.getUsername());
			f.write(username1, 50);

			char questionArea1[50];
			strcpy(questionArea1, newq.getQuestionArea());
			f.write(questionArea1, 50);

			char question1[500];
			strcpy(question1, newq.getQuestion());
			f.write(question1, 500);

			f.write((char*)&(newq.votes), sizeof(int));
			char dateQ1[50];
			strcpy(dateQ1, newq.dateQ);
			f.write(dateQ1, 50);
		}
		else
		{
			cout << "The file cannot be opened.1";
		}


		f.close();
	}
	static void DeserializeQuestion(Question* &q, int& size) {
		ifstream f("Questions.dat", ios::in, ios::binary);
		int nb = 0;

		Question vector[100];
		if (f.is_open()){
			while (!(f.eof())) {
				f.read((char*)&(vector[nb].id), sizeof(int));
				f.read((char*)&(vector[nb].active), sizeof(int));

				char username1[50];
				f.read(username1, 50);
				vector[nb].u.setUsername(username1);

				char questionArea1[50];
				f.read(questionArea1, 50);
				vector[nb].setQuestionArea(questionArea1);

				char question[500];
				f.read(question, 500);
				vector[nb].setQuestion(question);

				f.read((char*)&(vector[nb].votes), sizeof(int));

				char dateQ1[50];
				f.read(dateQ1, 50);
				vector[nb].setDateQ(dateQ1);

				nb++;
			}

			q = new Question[nb - 1];
			size = nb - 1;

			for (int i = 0; i < size; i++) {
				q[i] = vector[i];
			}
		}
		else {
			cout << "The questions file doesn't exist.";
		}

		f.close();
	}
	static void ReadFromTxt() {
		int size;
		ifstream fin;
		fin.open("QuestionsText.txt", ios::in);
		if (fin.is_open()) {
			fin >> size;
			cout << size;
			char buffer[100];
			fin.getline(buffer, 100);
			Question* questions = new Question[size];
			for (int i = 0; i < size; i++){
				fin >> questions[i];
			}

			ofstream fout;
			fout.open("Questions.dat");
			if (fout.is_open()){
				Question::SerializeQuestion(questions, size);
				fout.close();
			}

			fin.close();

		}
		else {
			cout << "The file cannot be opened.";
		}

	}
	static void ShowFromBinary() {
		Question* lista;
		int size = 0;
		Question::DeserializeQuestion(lista, size);
		for (int i = 0; i < size; i++) {
			cout << lista[i];
		}

	}
	static void BinaryToTxt() {
		Question* lista;
		int size = 0;
		Question::DeserializeQuestion(lista, size);
		for (int i = 0; i < size; i++) {
			lista[i].addToTxt();
		}
	}
	static void incQuest() {
		int nbofq;
		ifstream z;
		z.open("nbOfQuestions.txt", ios::in);
		if (z.is_open()) {
			z >> nbofq;
		}
		else {
			cout << "The file can not be opened.";
		}
		z.close();

		ofstream k;
		k.open("nbOfQuestions.txt", ios::trunc);
		if (k.is_open()) {
			nbofq++;
			k << nbofq;
		}
		else {
			cout << "The file can not be opened.";
		}


	}

	static int getNbOfQuestionsTxt() {
		fstream f;
		f.open("nbOfQuestions.txt", ios::in);
		if (f.is_open()){

			int x;
			f >> x;
			return x;

			f.close();
		}
		else{
			ofstream x1;
			x1.open("nbOfQuestions.txt", ios::out);
			x1 << "0";
			x1.close();
			return 0;
		}
	}
	static void setNbOfQuestionsTxt(int nbofQuestions){
		ofstream f;
		f.open("nbOfQuestions.txt", ios::out);
		if (f.is_open()) {
			f << nbofQuestions;
			f.close();
		}
		else {
			cout << "The file can not be opened";
		}
	}

	static void Add1Vote(int id){
		Question* lista;
		int size = 0;
		Question::DeserializeQuestion(lista, size);
		for (int i = 0; i < size; i++) {
			if (lista[i].getId() == id) {
				lista[i].votes++;

				SimpleUser* listau;
				int sizeu = 0;
				SimpleUser::DeserializeSimpleUser(listau, sizeu);
				for (int j = 0; j < sizeu; j++) {
					if (!strcmp(lista[i].getUsername(), listau[j].getUsername())){
						listau[j].addRep(5);
					}
				}
				SimpleUser::SerializeSimpleUser(listau, sizeu);

			}
		}
		Question::SerializeQuestion(lista, size);



	}


	static void ShowQuestions() {
		Question* qlist;
		int sizeq = 0;

		Question::DeserializeQuestion(qlist, sizeq);
		for (int i = 0; i < sizeq; i++) {
			cout << qlist[i];
		}
	}

	static void ShowInactiveQuestions() {

		Question* qlist;
		int sizeq = 0;
		int count = 0;
		Question::DeserializeQuestion(qlist, sizeq);
		for (int i = 0; i < sizeq; i++) {
			if (qlist[i].active == 0){
				cout << qlist[i];
				count++;
			}
		}
		if (count == 0) {
			cout << "There are no deleted questions.";
		}
	}

	static void ShowActiveQuestions() {

		Question* qlist;
		int sizeq = 0;
		int count = 0;
		Question::DeserializeQuestion(qlist, sizeq);
		for (int i = 0; i < sizeq; i++) {
			if (qlist[i].active == 1)
				cout << qlist[i];
			count++;
		}
		if (count == 0) {
			cout << "There are no active questions.";
		}
	}

	static void sortRaport() {
		Question* lista;
		int size = 0;
		Question::DeserializeQuestion(lista, size);
		Question aux;

		for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
		if (lista[i].getVotes()<lista[j].getVotes()){
			aux = lista[i];
			lista[i] = lista[j];
			lista[j] = aux;
		}

		for (int i = 0; i < size; i++){
			cout << endl << lista[i];
			lista[i].addToTxt();
		}

		cout << "The raport has been created.";
	}


	friend istream& operator>>(istream&, Question&);
	friend ostream& operator<<(ostream&, Question&);
	friend ofstream& operator<<(ofstream&, Question&);
	friend ifstream& operator>>(ifstream&, Question&);
};

ostream& operator<<(ostream& out, Question& s1)
{
	out << endl << "Question Id:" << s1.getId();
	out << endl << "Username: " << s1.getU().getUsername();
	out << endl << "QuestionArea: " << s1.getQuestionArea();
	out << endl << "Question: " << s1.getQuestion();
	out << endl << "Votes: " << s1.getVotes();
	out << endl << "Active:" << s1.getActive();
	out << endl << "Date: " << s1.getDateQ();

	return out;
}
istream& operator>>(istream& in, Question& s1)
{
	char questarea[50];
	cout << "Enter the question area:"; fflush(stdin);
	in.getline(questarea, 50);

	if (s1.QuestionArea != NULL)
	{
		delete[] s1.QuestionArea;
	}
	if (questarea != NULL)
	{
		s1.QuestionArea = new char[strlen(questarea) + 1];
		strcpy(s1.QuestionArea, questarea);
	}
	else
	{
		s1.QuestionArea = new char[strlen("N/A") + 1];
		strcpy(s1.QuestionArea, "N/A");
	}


	char question[500];
	cout << "Enter the question: "; fflush(stdin);
	in.getline(question, 100);
	if (s1.question != NULL)
	{
		delete[] s1.question;
	}
	if (question != NULL)
	{
		s1.question = new char[strlen(question) + 1];
		strcpy(s1.question, question);
	}
	else
	{
		s1.question = new char[strlen("N/A") + 1];
		strcpy(s1.question, "N/A");
	}
	s1.active = 1;
	s1.votes = 0;
	time_t now = time(0);
	strcpy(s1.dateQ, ctime(&now));


	return in;
}

ofstream& operator<<(ofstream& fout, Question& q) {
	fout.open("QuestionsTextOrdered.txt", ios::trunc);
	if (fout) {
		fout << endl << q.getActive();
		fout << endl << q.u.getUsername();
		fout << endl << q.getQuestionArea();
		fout << endl << q.getQuestion();
		fout << endl << q.getVotes();
		fout << endl << q.getDateQ();
	}
	else {
		cout << "The file can not be opened.";
	}
	fout.close();
	return fout;
}
ifstream& operator>>(ifstream& fin, Question& q) {
	char linie[100];
	char linie2[500];
	char aux[2];
	fin >> q.active;

	fin.getline(aux, 2);

	fin.getline(linie, 100);
	q.u.setUsername(linie);

	fin.getline(linie, 100);
	q.setQuestionArea(linie);

	fin.getline(linie, 500);
	q.setQuestion(linie);

	fin >> q.votes;

	fin.getline(aux, 2);
	fin.getline(linie, 100);
	q.setDateQ(linie);

	return fin;
}

int Question::nbOfQuestions = 0;

class Register
{
private:
	const int  id;
	static int nbOfReg;
	char registrationDate[26];
	SimpleUser u;

public:


	Register() : id(nbOfReg)
	{
		SimpleUser x;
		u = x;

		time_t now = time(0);
		strcpy(this->registrationDate, ctime(&now));

		nbOfReg++;

	}
	Register(SimpleUser& x) : id(nbOfReg)
	{
		u = x;

		strcpy(registrationDate, x.getDate());

		nbOfReg++;

	}
	Register(SimpleUser& x, char* reg) : id(nbOfReg)
	{
		u = x;
		if (reg != NULL)
		{
			strcpy(registrationDate, reg);
		}
		else
		{
			strcpy(registrationDate, x.getDate());
		}
		nbOfReg++;

	}
	Register(const Register& copy) : id(nbOfReg)
	{
		this->u = copy.u;
		if (copy.registrationDate != NULL)
		{
			strcpy(this->registrationDate, copy.registrationDate);
		}
		else
		{
			strcpy(this->registrationDate, copy.registrationDate);
		}
		nbOfReg++;

	}
	Register& operator=(const Register& copy)
	{

		this->u = copy.u;

		if (copy.registrationDate != NULL)
		{
			strcpy(this->registrationDate, copy.registrationDate);
		}
		else
		{
			strcpy(this->registrationDate, copy.registrationDate);
		}
		nbOfReg++;

	}
	~Register()
	{
		nbOfReg--;
	}

	SimpleUser& getUser()
	{
		return this->u;
	}
	char* getRegistrationDate()
	{
		return registrationDate;
	}
	void setUser()
	{
		cin >> this->u;
	}
	void setRegistrationDate()
	{
		time_t now = time(0);
		char day[4];
		char month[4];
		char nbDay[3];
		char hour[3];
		char min[3];
		char sec[3];
		char year[5];

		int ok = 1;
		while (ok)
		{
			cout << endl << "Day ( ex Monday-> Mon): ";
			fflush(stdin);
			cin >> day;

			cout << endl << "Month ( ex December-> Dec): ";
			fflush(stdin);
			cin >> month;

			cout << endl << "nbDay ( ex 23): ";
			fflush(stdin);
			cin >> nbDay;

			cout << endl << "Hour ( 24h - format): ";
			fflush(stdin);
			cin >> hour;

			cout << endl << "Minute: ";
			fflush(stdin);
			cin >> min;

			cout << endl << "Second: ";
			fflush(stdin);
			cin >> sec;

			cout << endl << "Year: ";
			fflush(stdin);
			cin >> year;

			if ((strlen(day) == 3) && (strlen(month) == 3) && (atoi(nbDay) <= 31 && atoi(nbDay) >= 0) && (atoi(hour) <= 24 && atoi(hour) >= 0) &&
				(atoi(min) <= 60 && atoi(min) >= 0) && (atoi(sec) <= 60 && atoi(nbDay) >= 0) && (atoi(year) <= 2017 && atoi(year) >= 0))
			{
				this->registrationDate[0] = day[0];
				this->registrationDate[1] = day[1];
				this->registrationDate[2] = day[2];
				this->registrationDate[3] = ' ';

				this->registrationDate[4] = month[0];
				this->registrationDate[5] = month[1];
				this->registrationDate[6] = month[2];
				this->registrationDate[7] = ' ';

				if (strlen(nbDay) == 1)
				{
					this->registrationDate[8] = '0';
					this->registrationDate[9] = nbDay[0];
				}
				else
				{
					this->registrationDate[8] = nbDay[0];
					this->registrationDate[9] = nbDay[1];
				}

				this->registrationDate[10] = ' ';

				if (strlen(hour) == 1)
				{
					this->registrationDate[11] = '0';
					this->registrationDate[12] = hour[0];
				}
				else
				{
					this->registrationDate[11] = hour[0];
					this->registrationDate[12] = hour[1];
				}


				this->registrationDate[13] = ':';

				if (strlen(min) == 1)
				{
					this->registrationDate[14] = '0';
					this->registrationDate[15] = min[0];
				}
				else
				{
					this->registrationDate[14] = min[0];
					this->registrationDate[15] = min[1];
				}

				this->registrationDate[16] = ':';

				if (strlen(sec) == 1)
				{
					this->registrationDate[17] = '0';
					this->registrationDate[18] = sec[0];
				}
				else
				{
					this->registrationDate[17] = sec[0];
					this->registrationDate[18] = sec[1];
				}

				this->registrationDate[19] = ' ';

				this->registrationDate[20] = year[0];
				this->registrationDate[21] = year[1];
				this->registrationDate[22] = year[2];
				this->registrationDate[23] = year[3];


				this->registrationDate[24] = '\n';
				this->registrationDate[25] = '\0';

				ok = 0;
			}
			else
			{
				cout << "Press insert the data correctly!";
			}
		}
	}
	void addToTxt()
	{
		ofstream f;
		f << *this;

	}


	friend ofstream& operator <<(ofstream&, Register&);
	friend istream& operator>>(istream&, Register&);
};

istream& operator>>(istream& RegIn, Register& reg)
{
	RegIn >> reg.u;

	time_t now = time(0);
	strcpy(reg.registrationDate, ctime(&now));
	reg.addToTxt();
	return RegIn;
}

ofstream& operator<<(ofstream& fout, Register& r)
{
	fout.open("UsersResume.txt", ios::app);
	if (fout)
	{
		fout << r.u.getUsername() << ' ';
		fout << r.u.getPassword() << endl;
	}
	fout.close();
	return fout;

}


int Register::nbOfReg = 0;

class Login
{
private:
	const int id;
	static int nbOfLogs;
	char* username;
	char* password;
	char LastLoginDate[26];
	int ok;
public:


	Login() :id(nbOfLogs)
	{
		this->username = new char[strlen("N/A") + 1];
		strcpy(this->username, "N/A");

		this->password = new char[strlen("N/A") + 1];
		strcpy(this->password, "N/A");

		time_t now = time(0);
		strcpy(this->LastLoginDate, ctime(&now));

		nbOfLogs++;
	}
	Login(char* username, char* password) : id(nbOfLogs)
	{
		if (username != NULL)
		{
			this->username = new char[strlen(username) + 1];
			strcpy(this->username, username);
		}
		this->password = new char[strlen(password) + 1];
		strcpy(this->password, password);

		time_t now = time(0);
		strcpy(this->LastLoginDate, ctime(&now));

		nbOfLogs++;

	}
	Login(char* username, char* password, char* date) : id(nbOfLogs)
	{
		if (username != NULL)
		{
			this->username = new char[strlen(username) + 1];
			strcpy(this->username, username);
		}

		if (password != NULL)
		{
			this->password = new char[strlen(password) + 1];
			strcpy(this->password, password);
		}
		else
		{
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}

		if (date != NULL)
		{

			strcpy(this->LastLoginDate, date);
		}
		else
		{
			time_t now = time(0);
			strcpy(this->LastLoginDate, ctime(&now));
		}

		nbOfLogs++;

	}
	Login(const Login& l) : id(nbOfLogs)
	{
		if (l.username != NULL)
		{
			this->username = new char[strlen(l.username) + 1];
			strcpy(this->username, l.username);
		}

		if (l.password != NULL)
		{

			this->password = new char[strlen(l.password) + 1];
			strcpy(this->password, l.password);
		}
		else
		{
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}

		if (l.LastLoginDate != NULL)
		{

			strcpy(this->LastLoginDate, l.LastLoginDate);
		}
		else
		{
			time_t now = time(0);
			strcpy(this->LastLoginDate, ctime(&now));
		}

		nbOfLogs++;

	}
	Login operator=(const Login& l)
	{
		if (this->username != NULL)
		{
			delete[] this->username;
		}

		if (l.username != NULL)
		{
			this->username = new char[strlen(l.username) + 1];
			strcpy(this->username, l.username);
		}
		if (this->password != NULL)
		{
			delete[] this->password;
		}

		if (l.password != NULL)
		{

			this->password = new char[strlen(l.password) + 1];
			strcpy(this->password, l.password);
		}
		else
		{
			this->password = new char[strlen("N/A") + 1];
			strcpy(this->password, "N/A");
		}

		if (l.LastLoginDate != NULL)
		{

			strcpy(this->LastLoginDate, l.LastLoginDate);
		}
		else
		{
			time_t now = time(0);
			strcpy(this->LastLoginDate, ctime(&now));
		}

		nbOfLogs++;
		return *this;
	}
	~Login()
	{
		if (this->username != NULL)
		{
			delete[] this->username;
		}

		if (this->password != NULL)
		{
			delete[] this->password;
		}
		nbOfLogs--;
	}

	bool login1()
	{
		char username1[50];
		char password1[50];
		cout << endl << "Username: "; fflush(stdin); cin >> username1;
		cout << endl << "Password: "; fflush(stdin); cin >> password1;
		if (this->username != NULL)
		{
			delete[] this->username;
		}

		this->username = new char[strlen(username1) + 1];
		strcpy(this->username, username1);

		if (this->password != NULL)
		{
			this->password = new char[strlen(password1) + 1];
			strcpy(this->password, password1);
		}
		ifstream f;
		f >> *this;
		if (this->ok == 1)
			return true;
		else
			return false;
	}
	char* getUsername()
	{
		return this->username;
	}
	char* getPassword()
	{
		return this->password;
	}

	void setUsername(char* username)
	{
		if (this->username != NULL)
		{
			delete[] this->username;
		}
		if (strlen(username) >= 5)
		{
			this->username = new char[strlen(username) + 1];
			strcpy(this->username, username);
		}
		else
		{
			cout << "The username must contain at least 5 characters.";
		}
	}
	void setPassword(char* password)
	{
		if (this->password != NULL)
		{
			delete[] this->password;
		}
		if (strlen(password) >= 8)
		{
			this->password = new char[strlen(password) + 1];
			strcpy(this->password, password);
		}
		else
		{
			cout << "The password must contain at least 8 characters.";
		}
	}

	friend ifstream& operator>>(ifstream&, Login&);
	friend ofstream& operator<<(ofstream&, Login&);

	void addToTxt()
	{
		ofstream kos;
		kos << *this;
	}
};
int Login::nbOfLogs = 0;
ifstream& operator>>(ifstream& fin, Login& l)
{
	fin.open("UsersResume.txt", ios::in);
	if (fin)
	{
		l.ok = 0;
		char linie[100];
		char val[100];
		strcpy(val, l.username);
		strcat(val, " ");
		strcat(val, l.password);
		while (fin.getline(linie, 100))
		{
			if (strcmp(val, linie) == 0)
			{
				l.ok = 1;

			}
		}


	}
	else
	{
		cout << "The file cannot be open.";
	}
	fin.close();
	return fin;
}
ofstream& operator<<(ofstream&  fout2, Login& l2)
{
	fout2.open("CurrentUser.txt", ios::trunc);
	if (fout2)
	{
		fout2 << l2.getUsername() << ' ';
		fout2 << l2.getPassword() << endl;
	}
	fout2.close();
	return fout2;
}


template <class T> class Lista{
private:
	int nbOfElements;
	T* lista;

public:
	Lista(){
		nbOfElements = 0;
		lista = NULL;
	}

	Lista(int nbOfElements, T* lista){
		if (nbOfElements > 0)
			this->nbOfElements = nbOfElements;
		else
			this->nbOfElements = 0;
		if (lista != NULL){
			this->lista = new T[this->nbOfElements];
			for (int i = 0; i < this->nbOfElements; i++)
				this->lista[i] = lista[i];
		}
		else
			this->lista = NULL;

	}
	~Lista(){
		if (this->lista != NULL)
		{

			delete[] this->lista;
		}
	}

	Lista& operator=(const Lista& c){
		if (c.elemente > 0)
			this->elemente = c.elemente;
		else
			this->elemente = 0;
		if (this->lista != NULL)
			delete[] this->lista;
		if (c.lista != NULL){
			this->lista = new T[this->elemente];
			for (int i = 0; i < elemente; i++)
			{
				this->lista[i] = c.lista[i];
			}
		}

		else
		{
			this->lista = NULL;
		}
		return *this;
	}

	T operator[](int index){

		if (index >= 0 && index < this->nbOfElements){
			return this->lista[index];
		}
		else
			throw("Index-ul nu se gaseste in lista");
	}

	void sortare(){
		T aux;
		for (int i = 0; i < this->nbOfElements - 1; i++)
		for (int j = i + 1; j < this->nbOfElements; j++)
		if (this->lista[i].getReputation()<this->lista[j].getReputation()){
			aux = this->lista[i];
			this->lista[i] = this->lista[j];
			this->lista[j] = aux;
		}
	}

	void afisareLista(){
		for (int i = 0; i < this->nbOfElements; i++){
			cout << lista[i];
		}
	}

	void addToTxt() {

		ofstream foutUser;

		for (int i = 0; i < this->nbOfElements; i++){
			cout << lista[i];


			foutUser.open("DataUsersOrdered.txt", ios::app);
			if (foutUser)
			{
				foutUser << lista[i].getType() << endl;
				foutUser << lista[i].getUsername() << endl;
				foutUser << lista[i].getPassword() << endl;
				foutUser << lista[i].getFullname() << endl;
				foutUser << lista[i].getEmail() << endl;
				foutUser << lista[i].getDate();
				foutUser << lista[i].getReputation() << endl;
				foutUser << lista[i].getBadges() << endl;
				foutUser << lista[i].getGender() << endl << endl;

			}
			foutUser.close();
		}
	}



};

class Menu
{
private:

	Register r;
	Login l;
	Question q;
	Answer a;

	Answer answers[100];
	Question questions[100];

	SimpleUser simpleUsers[100];
	Moderator moderators[100];
	Administrator administrators[100];

	SimpleUser currentUser;
	Moderator currentModerator;
	Administrator currentAdministrator;


	char* moderatorpasswordaccess;
	char* administratorpasswordaccess;

	int nbOfUsers = 0;
	int nbOfModerators = 0;
	int nbOfAdmin = 0;

	int nbOfQuestions = 0;
	int nbOfAns = 0;

public:



	void getMenu()
	{
		moderatorpasswordaccess = new char[strlen("moderator1") + 1];
		strcpy(moderatorpasswordaccess, "moderator1");

		administratorpasswordaccess = new char[strlen("administrator1") + 1];
		strcpy(administratorpasswordaccess, "administrator1");
		char passwordmod[50];
		char passwordadm[50];


		cout << "Welcome!";
		int d = 1;
		while (d != 3)
		{

			cout << endl << "Register          -> press 1."
				<< endl << "Login             -> press 2."
				<< endl << "Close the program -> press 3."
				<< endl << "Your decision: ";
			d;
			cin >> d;


			if (d == 1)
			{
				cout << endl << "Chose your type account:";
				cout << endl << "1 - Normal User";
				cout << endl << "2 - Moderator"; // moderator acces password
				cout << endl << "3 - Administrator"; //administrator acces password
				cout << endl << "4 - Back";
				cout << endl << "Your decision: ";
				int d1;
				cin >> d1;
				if (d1 == 1) {
					cout << endl << "Creating normal user account:" << endl;
					cin >> simpleUsers[nbOfUsers];

					SimpleUser::addUser(simpleUsers[nbOfUsers]);
					nbOfUsers++;
					cout << "Your account has been created!";
				}
				else if (d1 == 2) {


					cout << endl << "Firstly, you have to enter the moderator password acces.";
					cout << endl << "Password: ";

					cin >> passwordmod;

					if (!strcmp(passwordmod, moderatorpasswordaccess)) {

						cout << endl << "The password is correct.";
						cout << "Creating moderator account: " << endl;
						cin >> moderators[nbOfModerators];
						Moderator::addModerator(moderators[nbOfModerators]);
						nbOfModerators++;
						cout << "Your moderator account has been created!";
					}
					else {
						cout << "Access denied( Wrong passowrd).";
					}
				}

				else if (d1 == 3){

					cout << endl << "Firstly, you have to enter the administrator password access.";
					cout << endl << "Password: ";

					cin >> passwordadm;

					if (!strcmp(passwordadm, administratorpasswordaccess)) {

						cout << endl << "The password is correct.";
						cout << "Creating administrator account: " << endl;
						cin >> administrators[nbOfAdmin];
						Administrator::addAdministrator(administrators[nbOfAdmin]);
						nbOfAdmin++;
						cout << "Your administrator account has been created!";
					}
					else {
						cout << "Access denied( Wrong passowrd).";
					}

				}
			}
			else if (d == 2)
			{
				cout << endl << "Login as:";
				cout << endl << "1-Normal User";
				cout << endl << "2-Moderator";
				cout << endl << "3-Administrator";
				cout << endl << "4-Back";
				cout << endl << "Your decision: ";

				int decisionlogin;
				cin >> decisionlogin;


				if (decisionlogin == 1){


					int ttt = 0;
					while (ttt == 0)
					{
						int logok = 0;
						cout << endl << "Enter your username & password." << endl;

						cout << endl << "Username: ";
						char username1[50];
						cin >> username1;

						cout << endl << "Passowrd: ";
						char password1[50];
						cin >> password1;

						SimpleUser* lista;
						int size = 0;
						SimpleUser::DeserializeSimpleUser(lista, size);
						for (int i = 0; i < size; i++)
						{

							if (!strcmp(lista[i].getUsername(), username1) && !strcmp(lista[i].getPassword(), password1)) {

								currentUser = lista[i];
								ttt = 1;
								logok = 1;
							}
						}
						if (logok) {
							cout << endl << "You are logged in.";

							int simpleuserdec = 0;

							while (simpleuserdec != 6) {
								cout << endl << endl << "What do you want now?";
								cout << endl << "1-Show all the questions.";
								cout << endl << "2-Create a question.";
								cout << endl << "3-Show all the answers.";
								cout << endl << "4-Create an answer.";
								cout << endl << "5-Search questions by the question area filter";
								cout << endl << "6-Show answers of a question by the question id";
								cout << endl << "7-Go back.";
								cout << endl << "Your decision: ";




								cin >> simpleuserdec;
								if (simpleuserdec == 1) {

									Question::ShowActiveQuestions();

									int simpleuserdec1 = 0;

									while (simpleuserdec1 != 3){
										cout << endl << endl << "What do you want now?";
										cout << endl << endl << "1-Vote a question";
										cout << endl << "2- Answer to a question";
										cout << endl << "3- Go back.";
										cin >> simpleuserdec1;
										if (simpleuserdec1 == 1){
											cout << "Enter the question Id.";
											int questionidv;
											cin >> questionidv;
											if (questionidv > Question::getNbOfQuestionsTxt()) {
												cout << "There is no question with that id.";
											}
											else {
												Question::Add1Vote(questionidv);

											}
										}
										else if (simpleuserdec1 == 2) {
											nbOfAns = Answer::getNbOfAnswersTxt();
											cin >> answers[nbOfAns];
											answers[nbOfAns].setU(currentUser);
											answers[nbOfAns].setId(nbOfAns);
											Answer::addAnswer(answers[nbOfAns]);
											cout << "The answer was succesfully added";
											nbOfAns++;
											Answer::setNbOfAnswersTxt(nbOfAns);
										}
									}
								}

								if (simpleuserdec == 2) {

									nbOfQuestions = Question::getNbOfQuestionsTxt();
									cin >> questions[nbOfQuestions];
									questions[nbOfQuestions].setU(currentUser);
									questions[nbOfQuestions].setId(nbOfQuestions);
									Question::addQuestion(questions[nbOfQuestions]);
									cout << "The question was succesfully added.";
									nbOfQuestions++;
									Question::setNbOfQuestionsTxt(nbOfQuestions);

								}
								if (simpleuserdec == 3) {

									Answer::ShowFromBinary();
									int simpleuserdec3 = 0;

									while (simpleuserdec3 != 3){
										cout << endl << endl << "What do you want now?";
										cout << endl << "1-Vote an answer";

										cout << endl << "2- Go back.";
										cin >> simpleuserdec3;

										if (simpleuserdec3 == 1){
											cout << "Enter the answer Id.";
											int answerid;
											cin >> answerid;
											if (answerid > Answer::getNbOfAnswersTxt()) {
												cout << "There is no question with that id.";
											}
											else {
												Answer::Add1Vote(answerid);

											}
										}
										else {
											simpleuserdec3 = 3;
										}


									}
								}
								if (simpleuserdec == 4){
									nbOfAns = Answer::getNbOfAnswersTxt();
									cin >> answers[nbOfAns];
									answers[nbOfAns].setU(currentUser);
									answers[nbOfAns].setId(nbOfAns);
									Answer::addAnswer(answers[nbOfAns]);
									cout << "The answer was succesfully added";
									nbOfAns++;
									Answer::setNbOfAnswersTxt(nbOfAns);
								}
								else if (simpleuserdec == 5) {
									cout << endl << "Enter the question area: ";
									char questionarea[50];
									fflush(stdin);
									cin.getline(questionarea, 50);
									Question::SearchQueston(questionarea);
								}
								else if (simpleuserdec == 6){
									cout << "Enter the question id";
									int idq;
									cin >> idq;
									Answer::ShowAnswersIdQuestion(idq);
								}
								else {
									simpleuserdec == 7;
								}
							}
						}
						else {
							cout << endl << "Wrong username & password";
							cout << endl << "1- Try again";
							cout << endl << "2- Go back";
							cout << endl << "Your decision: ";
							int tryagain;
							cin >> tryagain;
							if (tryagain == 2) {
								ttt = 1;
							}
						}
					}
				}
				else if (decisionlogin == 2) {
					int ttt = 0;
					while (ttt == 0)
					{
						int logok = 0;
						cout << endl << "Enter your username & password." << endl;

						cout << endl << "Username: ";
						char username1[50];
						cin >> username1;

						cout << endl << "Passowrd: ";
						char password1[50];
						cin >> password1;

						Moderator* lista;
						int size = 0;
						Moderator::DeserializeUsers(lista, size);
						for (int i = 0; i < size; i++)
						{

							if (!strcmp(lista[i].getUsername(), username1) && !strcmp(lista[i].getPassword(), password1)) {

								currentModerator = lista[i];
								ttt = 1;
								logok = 1;
							}
						}
						if (logok) {
							cout << endl << "You are logged in as moderator.";

							int simpleuserdec = 0;

							while (simpleuserdec != 6) {
								cout << endl << endl << "What do you want now?";
								cout << endl << "1-Show all the questions.";
								cout << endl << "2-Create a question.";
								cout << endl << "3-Show all the answers.";
								cout << endl << "4-Create an answer.";
								cout << endl << "5-Show the deleted questions.";
								cout << endl << "6- Search questions by the question area filter.";
								cout << endl << "7- Show answers of a question by the question id.";
								cout << endl << "8-Go back.";
								cout << endl << "Your decision: ";




								cin >> simpleuserdec;
								if (simpleuserdec == 1) {

									Question::ShowActiveQuestions();

									int simpleuserdec1 = 0;

									while (simpleuserdec1 != 3){
										cout << endl << endl << "What do you want now?";
										cout << endl << "1-Vote a question";
										cout << endl << "2- Answer to a question";
										cout << endl << "3- Go back.";
										cin >> simpleuserdec1;
										if (simpleuserdec1 == 1){
											cout << "Enter the question Id.";
											int questionidv;
											cin >> questionidv;
											if (questionidv > Question::getNbOfQuestionsTxt()) {
												cout << "There is no question with that id.";
											}
											else {
												Question::Add1Vote(questionidv);

											}
										}
										else if (simpleuserdec1 == 2) {
											nbOfAns = Answer::getNbOfAnswersTxt();
											cin >> answers[nbOfAns];
											answers[nbOfAns].setU(currentModerator);
											answers[nbOfAns].setId(nbOfAns);
											Answer::addAnswer(answers[nbOfAns]);
											cout << "The answer was succesfully added";
											nbOfAns++;
											Answer::setNbOfAnswersTxt(nbOfAns);
										}
									}
								}
								else
								if (simpleuserdec == 2) {

									nbOfQuestions = Question::getNbOfQuestionsTxt();
									cin >> questions[nbOfQuestions];
									questions[nbOfQuestions].setU(currentModerator);
									questions[nbOfQuestions].setId(nbOfQuestions);
									Question::addQuestion(questions[nbOfQuestions]);
									cout << "The question was succesfully added.";
									nbOfQuestions++;
									Question::setNbOfQuestionsTxt(nbOfQuestions);

								}
								else if (simpleuserdec == 3) {

									Answer::ShowFromBinary();
									int simpleuserdec3 = 0;

									while (simpleuserdec3 != 3){
										cout << endl << endl << "What do you want now?";
										cout << endl << "1-Vote an answer";

										cout << endl << "2- Go back.";
										cin >> simpleuserdec3;

										if (simpleuserdec3 == 1){
											cout << "Enter the answer Id.";
											int answerid;
											cin >> answerid;
											if (answerid > Answer::getNbOfAnswersTxt()) {
												cout << "There is no question with that id.";
											}
											else {
												Answer::Add1Vote(answerid);

											}
										}
										else { simpleuserdec3 = 3; }


									}
								}
								else if (simpleuserdec == 4){
									nbOfAns = Answer::getNbOfAnswersTxt();
									cin >> answers[nbOfAns];
									answers[nbOfAns].setU(currentModerator);
									answers[nbOfAns].setId(nbOfAns);
									Answer::addAnswer(answers[nbOfAns]);
									cout << "The answer was succesfully added";
									nbOfAns++;
									Answer::setNbOfAnswersTxt(nbOfAns);
								}

								else if (simpleuserdec == 5){
									Question::ShowInactiveQuestions();
								}
								else if (simpleuserdec == 6){

									cout << endl << "Enter the question area: ";
									char questionarea[50];
									fflush(stdin);
									cin.getline(questionarea, 50);
									Question::SearchQueston(questionarea);


								}
								else if (simpleuserdec == 7){
									cout << "Enter the question id";
									int idq;
									cin >> idq;
									Answer::ShowAnswersIdQuestion(idq);
								}
								else {
									simpleuserdec = 8;
								}


							}
						}
						else {
							cout << endl << "Wrong username & password";
							cout << endl << "1- Try again";
							cout << endl << "2- Go back";
							cout << endl << "Your decision: ";
							int tryagain;
							cin >> tryagain;
							if (tryagain != 1) {
								ttt = 1;
							}
						}
					}



				}
				else if (decisionlogin == 3) {

					int ttt = 0;
					while (ttt == 0)
					{
						int logok = 0;
						cout << endl << "Enter your username & password." << endl;

						cout << endl << "Username: ";
						char username1[50];
						cin >> username1;

						cout << endl << "Passowrd: ";
						char password1[50];
						cin >> password1;

						Administrator* lista;
						int size = 0;
						Administrator::DeserializeAdministrator(lista, size);
						for (int i = 0; i < size; i++)
						{

							if (!strcmp(lista[i].getUsername(), username1) && !strcmp(lista[i].getPassword(), password1)) {

								currentAdministrator = lista[i];
								ttt = 1;
								logok = 1;
							}
						}
						if (logok) {
							cout << endl << "You are logged in as administrator.";

							int simpleuserdec = 0;

							while (simpleuserdec != 8) {
								cout << endl << endl << "What do you want now?";
								cout << endl << "1-Show the users database.";
								cout << endl << "2-Show all the questions.";
								cout << endl << "3-Show all the answers.";
								cout << endl << "4-Show users order DESC by reputation.";
								cout << endl << "5-Create a raport with all users order DESC by reputation.";
								cout << endl << "6- Create a raport with all questions order DESC by votes";
								cout << endl << "7-Create a raport with all users.";
								cout << endl << "8-Go back.";
								cout << endl << "Your decision: ";


								cin >> simpleuserdec;
								if (simpleuserdec == 1) {

									SimpleUser* ulist;
									int sizeu = 0;
									SimpleUser::DeserializeSimpleUser(ulist, sizeu);
									cout << endl << endl << " Lista utilizatori: " << endl;
									for (int i = 0; i < sizeu; i++) {
										cout << endl << ulist[i];
										cout << "Password: " << ulist[i].getPassword();
									}


									int simpleuserdec1 = 0;
									while (simpleuserdec1 != 2) {
										cout << endl << "1- Edit an user.";
										cout << endl << "2- Go back.";
										cout << endl << "Your decision:";
										cin >> simpleuserdec1;
										if (simpleuserdec1 == 1) {
											char username1[50];
											cout << endl << "Enter the user account ( username ).";
											cin >> username1;
											Moderator::Edit(username1);
										}
										else {
											simpleuserdec1 == 2;
										}
									}

								}

								if (simpleuserdec == 2) {

									Question::ShowFromBinary();

									int simpleuserdec1 = 0;

									while (simpleuserdec1 != 3){
										cout << endl << endl << "What do you want now?";
										cout << endl << "1-Edit a question";
										cout << endl << "2-Delete a question";
										cout << endl << "3- Go back.";
										cout << endl << "Your decision: ";

										cin >> simpleuserdec1;

										if (simpleuserdec1 == 1){
											cout << "Enter the question Id.";
											int questionidv;
											cin >> questionidv;
											if (questionidv > Question::getNbOfQuestionsTxt()) {
												cout << "There is no question with that id.";
											}
											else {

												Question::EditQuestion(questionidv);

											}
										}
										else if (simpleuserdec1 == 2) {

											cout << "Enter the question Id.";
											int questionidv;
											cin >> questionidv;
											if (questionidv > Question::getNbOfQuestionsTxt()) {
												cout << "There is no question with that id.";
											}
											else {

												Question::DeleteQuestion(questionidv);

											}

										}
										else {
											simpleuserdec1 = 3;
										}
									}

								}
								if (simpleuserdec == 3) {

									Answer::ShowFromBinary();

									int simpleuserdec1 = 0;

									while (simpleuserdec1 != 3){
										cout << endl << endl << "What do you want now?";
										cout << endl << "1-Edit an answer.";
										cout << endl << "3- Go back.";

										cin >> simpleuserdec1;

										if (simpleuserdec1 == 1){
											cout << "Enter the answer id.";
											int answerid;
											cin >> answerid;
											if (answerid > Answer::getNbOfAnswersTxt()) {
												cout << "There is no answer with that id.";
											}
											else {

												Answer::EditAnswer(answerid);

											}
										}
										else if (simpleuserdec1 == 2) {

											cout << "Enter the question Id.";
											int questionidv;
											cin >> questionidv;
											if (questionidv > Question::getNbOfQuestionsTxt()) {
												cout << "There is no question with that id.";
											}
											else {

												Question::DeleteQuestion(questionidv);

											}

										}
									}

								}
								if (simpleuserdec == 4){

									SimpleUser* lista;
									int size = 0;
									SimpleUser::DeserializeSimpleUser(lista, size);

									Lista<SimpleUser> lista1(size, lista);
									lista1.sortare();
									lista1.afisareLista();


								}
								else if (simpleuserdec == 5) {
									SimpleUser* lista;
									int size = 0;
									SimpleUser::DeserializeSimpleUser(lista, size);

									Lista<SimpleUser> lista1(size, lista);
									lista1.sortare();
									lista1.afisareLista();
									lista1.addToTxt();
									cout << endl << "The raport has been created." << endl;
								}
								else if (simpleuserdec == 6) {
									Question::sortRaport();
								}
								else if (simpleuserdec == 7) {
									SimpleUser* lista;
									int size = 0;
									SimpleUser::DeserializeSimpleUser(lista, size);

									for (int i = 0; i < size; i++){
										lista[i].addToTxt();
									}
									
									cout << endl<<"Done.";

								}
								else {
									simpleuserdec = 8;
								}

							}
						}
						else {
							cout << endl << "Wrong username & password";
							cout << endl << "1- Try again";
							cout << endl << "2- Go back";
							cout << endl << "Your decision: ";
							int tryagain;
							cin >> tryagain;
							if (tryagain == 2) {
								ttt = 1;
							}
						}
					}

				}
			}
			else {
				d = 3;
			}
		}
		cout <<endl<< "Have a nice day!"<<endl<<endl;
	}
};



void main() {

	Menu m;
	m.getMenu();

	/*SimpleUser* lista;
	int size = 0;
	SimpleUser::DeserializeSimpleUser(lista, size);

	Lista<SimpleUser> lista1(size, lista);
	lista1.sortare();
	lista1.afisareLista();
	lista1.addToTxt();*/


	//SimpleUser* lista;
	//int size = 0;
	//SimpleUser::DeserializeSimpleUser(lista, size);

	//Lista<SimpleUser> lista1(size, lista);
	//lista1.sortare();
	//lista1.afisareLista();

	/*SimpleUser* lista;
	int size = 0;
	SimpleUser::DeserializeSimpleUser(lista, size);
	for (int i = 0; i < size; i++)
	{
	cout << lista[i];
	}
	*/
	/*SimpleUser* ulist;
	int sizeu = 0;
	SimpleUser::DeserializeSimpleUser(ulist, sizeu);
	for (int i = 0; i < sizeu; i++) {
	cout << ulist[i];
	}*/


	/*SimpleUser* ulist2;
	int sizeu2 = 0;
	SimpleUser::DeserializeSimpleUser(ulist2, sizeu2);
	for (int i = 0; i < sizeu2; i++) {
	cout << ulist2[i];
	}*/
	/*SimpleUser ================================================*/

	/*SimpleUser a;
	SimpleUser b("mihaib", "omleta123", "a.mihai@yahoo.com", 3);
	SimpleUser c("mihaib11", "parola1234", "email@yahoo.com", "Mihai Bucur", 2, "Helper", "Male");
	SimpleUser d(b);
	SimpleUser e(c);
	SimpleUser f;
	a = c;
	SimpleUser* lista1 = new SimpleUser[3];
	for (int i = 0; i < 3; i++) {
	cin >> lista1[i];
	}
	SimpleUser::SerializeSimpleUser(lista1, 3);
	SimpleUser h;
	cin >> h;
	SimpleUser::addUser(h);
	SimpleUser* lista2;
	int size = 0;
	SimpleUser::DeserializeSimpleUser(lista2, size);
	for (int i = 0; i < size; i++) {
	cout << lista2[i];
	}*/

	////Moderator =======================================================
	/*Moderator* lista4 = new Moderator[2];
	cin >> lista4[0];
	Moderator::addModerator(lista4[0]);
	cin >> lista4[1];
	Moderator::addModerator(lista4[1]);

	Moderator* lista3;
	int size1 = 0;
	Moderator::DeserializeUsers(lista3, size1);
	for (int i = 0; i < size1; i++) {
	cout << endl;
	cout << lista3[i];
	}*/

	//Questions ==========================================================================
	//Question q1;
	//Question q2("Mihai");
	//SimpleUser c("metezu1", "metezu1234", "email@yahoo.com", "Mihai Bucur", 2, "Helper", "Male");
	//SimpleUser d("meteze2", "metezu12345", "gmail@yahoo.com", "Ionut Bucur", 2, "Friendly", "Female");
	//Question q4(c, "JAVA", "Ce este un ArrayList?");
	//Question q5(d, "C++", "C++ sau Java?", 3);
	//Question q6(c, "KDA", "Nu?", 5);
	//q4 = q5;
	///*cin >> q1;
	//cout << q1;*/

	//Question ans[3] {q6, q4, q5};
	//Question::SerializeQuestion(ans, 3);
	//Question qnew;
	//cin >> qnew;
	//Question::addQuestion(qnew);
	//Question* qlist;
	//int sizeq = 0;
	//Question::DeserializeQuestion(qlist, sizeq);
	//for (int i = 0; i < sizeq; i++) {
	//	cout << qlist[i];
	//}



	//ANSWERS ==================================================================================
	/*int nbbb = 0;
	Answer* x = new Answer[3];
	for (int i = 0; i < 3; i++) {
	cin >> x[i];
	x[i].setId(nbbb);
	nbbb++;
	}
	Answer::SerializeAnswer(x, 3);
	Answer y;
	cin >> y;
	nbbb++;
	y.setId(nbbb++);
	Answer::addAnswer(y);
	Answer* listaa;
	int size = 0;
	Answer::DeserializeAnswer(listaa, size);
	for (int i = 0; i < size; i++) {
	cout << listaa[i];
	}*/

	//Administrator ==========================================

	/*Administrator* x = new Administrator[2];
	cin >> x[0];
	cin >> x[1];
	Administrator::SerializeAdministrator(x, 2);
	Administrator y;
	cin >> y;
	Administrator::addAdministrator(y);*/
	/*Administrator* listagoala;
	int size = 0;

	Administrator::DeserializeAdministrator(listagoala, size);
	for (int i = 0; i < size; i++) {
	cout << listagoala[i];
	}
	*/


}
