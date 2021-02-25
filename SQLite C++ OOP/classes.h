#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;
class ExceptionPoo {

};

void exit() {
    throw ExceptionPoo();
}

class CreateTable {

    char* name = nullptr;
    string* columns = nullptr;
    string* types = nullptr;
    string* values = nullptr;
    int noOfColumns = 0;

public:
    CreateTable() {}
    void setName(const char* name) {
        if (name != nullptr)
        {
            if (this->name != nullptr)delete[] this->name;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }

    }
    const char* getName() const { if (this->name != nullptr) return this->name; }
    string* getColumns() const { return this->columns; }
    string* getTypes() const { return this->types; }
    string* getValues() const { return this->values; }
    int  getNoOfColumns() const { return this->noOfColumns; }


    CreateTable(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    CreateTable(const CreateTable& C) {
        this->name = new char[strlen(C.name) + 1];
        strcpy(this->name, C.name);
        delete[] this->columns;
        delete[] this->types;
        delete[] this->values;
        this->columns = new string[C.noOfColumns];
        this->values = new string[C.noOfColumns];
        this->types = new string[C.noOfColumns];
        for (int i = 0; i < this->noOfColumns; i++)
        {
            this->columns[i] = C.columns[i];
            this->values[i] = C.values[i];
            this->types[i] = C.types[i];

        }
    }
    void deleteColumn() {
        this->noOfColumns--;
        string* NewColumns = new string[this->noOfColumns];
        string* NewTypes = new string[this->noOfColumns];
        string* NewValues = new string[this->noOfColumns];
        for (int i = 0; i < this->noOfColumns; i++)
        {
            NewColumns[i] = this->columns[i];
            NewTypes[i] = this->types[i];
            NewValues[i] = this->values[i];
        }
        delete[] this->columns;
        delete[] this->types;
        delete[] this->values;
        this->columns = new string[this->noOfColumns];
        this->types = new string[this->noOfColumns];
        this->values = new string[this->noOfColumns];
        for (int i = 0; i < this->noOfColumns; i++)
        {

            this->columns[i] = NewColumns[i];
            this->types[i] = NewTypes[i];
            this->values[i] = NewValues[i];

        }

    }
    void deleteColumnAtIndex(int index) {
        this->noOfColumns--;
        string* NewColumns = new string[this->noOfColumns];
        string* NewTypes = new string[this->noOfColumns];
        string* NewValues = new string[this->noOfColumns];
        for (int i = 0; i < index; i++)
        {
            NewColumns[i] = this->columns[i];
            NewTypes[i] = this->types[i];
            NewValues[i] = this->values[i];
        }
        for (int i = index; i < this->noOfColumns; i++)
        {
            NewColumns[i] = this->columns[i + 1];
            NewTypes[i] = this->types[i + 1];
            NewValues[i] = this->values[i + 1];
        }
        delete[] this->columns;
        delete[] this->types;
        delete[] this->values;
        this->columns = new string[this->noOfColumns];
        this->types = new string[this->noOfColumns];
        this->values = new string[this->noOfColumns];
        for (int i = 0; i < this->noOfColumns; i++)
        {

            this->columns[i] = NewColumns[i];
            this->types[i] = NewTypes[i];
            this->values[i] = NewValues[i];

        }

    }
    void columnVector(string column, string type, string value) {
        vector<string> userString;
        for (int j = 0; j < this->noOfColumns; j++) {
            userString.push_back(column);
        }
    }


    void addColumn(string column, string type, string value) {
        this->noOfColumns++;
        string* oldColumns = new string[noOfColumns - 1];
        string* oldTypes = new string[noOfColumns - 1];
        string* oldValues = new string[noOfColumns - 1];
        if (this->noOfColumns >= 2)
        {
            for (int i = 0; i < this->noOfColumns - 1; i++)
            {
                oldColumns[i] = this->columns[i];
                oldTypes[i] = this->types[i];
                oldValues[i] = this->values[i];
            }
            delete[] this->columns;
            delete[] this->types;
            delete[] this->values;
        }
        this->columns = new string[this->noOfColumns];
        this->types = new string[this->noOfColumns];
        this->values = new string[this->noOfColumns];
        for (int i = 0; i < this->noOfColumns - 1; i++)
        {
            this->columns[i] = oldColumns[i];
            this->types[i] = oldTypes[i];
            this->values[i] = oldValues[i];
        }
        this->columns[this->noOfColumns - 1] = column;
        this->types[this->noOfColumns - 1] = type;
        this->values[this->noOfColumns - 1] = value;
    }
    string operator[](int value) {
        return  this->values[value];
    }
    CreateTable operator++(int) {
        CreateTable result = *this;
        this->addColumn("Grade", "Int", "10");
        return result;

    }

    CreateTable operator--(int) {
        CreateTable result = *this;
        this->deleteColumn();
        return result;
    }
    CreateTable operator--() {
        this->deleteColumn();
        return*this;
    }
    bool operator>(CreateTable C) {
        if (C.getTotal() > this->getTotal())return 1;
        else return 0;
    }
    bool operator==(CreateTable C) {
        if (strcmp(this->name, C.name) != 0)return 0;
        else
            for (int i = 0; i < this->noOfColumns; i++)
            {
                if (this->columns[i] != C.columns[i])return 0;
                if (this->values[i] != C.values[i]) return 0;
                if (this->types[i] != C.types[i])return 0;
            }
        return 1;
    }
    CreateTable operator=(int value) {
        CreateTable Result = *this;
        string val = "";
        val += value;
        Result.addColumn("Added Value", "int", val);

        return Result;


    }
    CreateTable operator!()
    {
        this->name = nullptr;
        this->noOfColumns = 0;
        this->columns = nullptr;
        this->values = nullptr;

    }
    CreateTable operator*(int value) {
        CreateTable result = *this;
        for (int i = 0; i < this->noOfColumns; i++)
        {
            int tempvalue = stoi(this->values[i]);
            tempvalue *= 2;
            result.values[i] = tempvalue;

        }
        return result;
    }
    CreateTable operator++() {
        this->addColumn("Grade", "int", "10");
        return *this;
    }


    int getTotal() {
        int total = 0;
        for (int i = 0; i < this->noOfColumns; i++) {
            total += std::stoi(this->values[i]);

        }
        return total;
    }
    operator int() {
        return this->getTotal();
    }






    operator string() {
        string values;
        for (int i = 0; i < this->noOfColumns; i++) {
            values += this->values[i];
            values += " ";

        }
        return values;

    }

    friend void operator>>(istream& input, CreateTable& F);
    friend void operator<<(ostream& console, CreateTable& F);
};




void operator<<(ostream& console, CreateTable& F)
{
    cout << "Name of the Table:" << endl;
    console << F.name;
    for (int i = 0; i < F.noOfColumns; i++)
    {
        cout << endl << "Column: ";
        cout << endl << F.columns[i];

        cout << endl << "The type of the value:" << endl;
        console << F.types[i];


        cout << endl << " value: ";
        cout << F.values[i];
    }
    cout << endl << "---------------------------------------------" << endl;



}
void operator>>(istream& input, CreateTable& F)
{
    cout << "TYPE DONE TO TERMINATE" << endl;
    cout << "Name=" << endl;
    char* newname = new char[200];
    input >> newname;
    F.setName(newname);
    for (int i = 0;; i++)
    {
        string tempColumn = "", tempType = "", TempValue = "";

        cout << "Column no:" << i << " =";
        input >> tempColumn;
        if (tempColumn == "DONE") break;
        cout << "Type= ";
        input >> tempType;
        cout << "Value=";
        input >> TempValue;
        F.addColumn(tempColumn, tempType, TempValue);

    }

}
class ImportTxt {
public:
    ImportTxt(const CreateTable& C) {
        string fisier = string(C.getName()) + ".txt";
        ifstream file(fisier, ios::in);
        if (file.is_open()) {
            char buffer[1000];
            file.getline(buffer, 1000);
            string name;
            name = string(buffer);
            int size;
            file >> size;
            string* info = new string[size * 3];
            for (int i = 0; i < 3 * size; i++) {
                char buffer[1000] = "";
                file >> buffer;
                info[i] = string(buffer);


            }
            for (int i = 0; i < 3 * size; i++)
                cout << info[i] << endl;
            delete[] info;

        }

    }
};
class ExportTxt {
public:
    ExportTxt(const CreateTable& C) {
        string fisier = string(C.getName()) + ".txt";
        //cout<<"Nume fisier:"<<fisier<<endl;
        ofstream fout(fisier);
        if (fout.is_open()) {
            fout << C.getName() << endl;
            int n = C.getNoOfColumns();
            fout << n << endl;
            for (int i = 0; i < n; i++) {
                fout << C.getColumns()[i] << endl;
                fout << C.getTypes()[i] << endl;
                fout << C.getValues()[i] << endl;

            }
            cout << "The table " << C.getName() << " has been successfully written into " << fisier << endl;
            cout << "The table " << C.getName() << " has been successfully written into " << string(C.getName()) + ".bin" << endl;

        }
        else {
            cout << "There was a problem writing to the file" << fisier << endl;
        }
    }
};



class DisplayTable {
    string name = " ";


public:
    DisplayTable(const CreateTable& C) {

        cout << "Table: " << C.getName() << endl;
        cout << "----------------------" << endl;
        int n = C.getNoOfColumns();
        for (int i = 0; i < n; i++) {
            cout << C.getColumns()[i] << " ";
            cout << "<" << C.getTypes()[i] << "> ";
            cout << C.getValues()[i] << endl;
        }
        cout << endl << endl;
    }
    DisplayTable(string name) {
        this->name = name;
        cout << "Do you want me to display the table " << name << " ?";
    }
};



class Delete {
    string name = "";
    string* columns = nullptr;
    int noOfColumns = 0;
public:
    Delete(CreateTable& C, string column) {
        this->columns = C.getColumns();
        this->noOfColumns = C.getNoOfColumns();


        for (int i = 0; i < this->noOfColumns; i++)
        {
            if (this->columns[i] == column)
            {
                C.deleteColumnAtIndex(i);

            }
        }
        bool ok = false;
        string nume = "";
        string nr = "";
        string col[20] = {};
        string typ[20] = {};
        string val[20] = {};
        string filename = string(C.getName()) + ".txt";
        ifstream fin(filename);
        int z = 0;
        while (!fin.eof() and z < 2) {
            if (z == 0)
                getline(fin, nume);
            else if (z == 1)
                getline(fin, nr);
            z++;
        }
        z = 0;
        while (!fin.eof()) {
            if (z % 3 == 0)
                getline(fin, col[z]);
            if (z % 3 == 1)
                getline(fin, typ[z]);
            if (z % 3 == 2)
                getline(fin, val[z]);
            if (col[z] == column);
            ok = true;
            z++;
        }

        fin.close();
        ofstream fout(filename, ios::out | ios::trunc);
        fout << nume << endl;
        if (ok == true)
            fout << stoi(nr) - 1 << endl;
        else
            fout << stoi(nr) << endl;


        for (int i = 0; i < z; i++)
        {
            if (col[i] == column)
                i++;
            else
            {
                fout << col[i] << endl << typ[i] << endl << val[i] << endl;
            }
        }
        fout.close();

    }
    Delete(string name, string column) {
        bool ok = false;
        string nume = "";
        string nr = "";
        string col[20] = {};
        string typ[20] = {};
        string val[20] = {};
        string filename = string(name + ".txt");
        ifstream fin(filename);
        int z = 0;
        while (!fin.eof() and z < 2) {
            if (z == 0)
                getline(fin, nume);
            else if (z == 1)
                getline(fin, nr);
            z++;
        }
        z = 0;
        while (!fin.eof()) {
            //if(z%3 == 0)
            getline(fin, col[z]);
            //if(z%3 == 1 )
            getline(fin, typ[z]);
            //if( z%3 == 2)
            getline(fin, val[z]);
            if (col[z] == column);
            ok = true;
            z++;
        }

        fin.close();

        ofstream fout(filename, ios::out | ios::trunc);
        fout << nume << endl;
        if (ok == true)
            fout << stoi(nr) - 1 << endl;
        else
            fout << stoi(nr) << endl;


        for (int i = 0; i < z; i++)
        {

            if (col[i] != column)
            {
                fout << col[i] << endl << typ[i] << endl << val[i] << endl;
            }
        }
        fout.close();
    }

};

class InsertInto {
    string column;
    string type;
    string value;
public:
    string getColumn()
    {
        return this->column;
    }
    string getType()
    {
        return this->type;
    }
    string getValue() {
        return this->value;
    }
    InsertInto() {

    }
    InsertInto(CreateTable& C, string column, string type, string value)
    {

        this->column = column;
        this->type = type;
        this->value = value;

        C.addColumn(this->column, this->type, this->value);

    }

    InsertInto operator++(int) {
        InsertInto result = *this;
        this->column = "SUCCESS";
        this->type = "EXAM";
        this->value = "10";
        return result;

    }
    InsertInto operator++() {
        this->column = "SUCCESS";
        this->type = "EXAM";
        this->value = "10";
        return *this;
    }
    InsertInto operator!() {
        this->column = "FAIL";
        this->type = "EXAM";
        this->value = "4";
        return *this;
    }
    bool operator==(InsertInto F) {
        if (this->value == F.value && this->column == F.column && this->type == F.type) return 1;
        else return 0;
    }
    bool operator>(InsertInto F) {
        if (stoi(this->value) > stoi(F.value))return 1;
        else
            return 0;

    }

    friend void operator>> (istream& input, InsertInto& F);
};
void operator<<(ostream& console, InsertInto& F) {
    console << "Column that needs to be added:" << endl;
    console << F.getColumn();
    console << " with the type:" << endl;
    console << F.getType();
    console << " and the value" << endl;
    console << F.getValue();

}
void operator>> (istream& input, InsertInto& F) {
    cout << "Name of the column: " << endl;
    input >> F.column;
    cout << endl << "Type: " << endl;
    input >> F.type;
    cout << endl << "Value: " << endl;
    input >> F.value;
}
class CreateIndex {
private:
    string name;
    string table;
    string column;
public:
    CreateIndex();
    CreateIndex(string, string, string);
    CreateIndex(const CreateIndex&);
    ~CreateIndex();
    string getName();
    string getTable();
    string getColumn();
    void setName(string);
    void setTable(string);
    void setColumn(string);
    CreateIndex operator=(CreateIndex c);
    friend ostream& operator<<(ostream&, const CreateIndex&);
    friend istream& operator>>(istream&, CreateIndex&);
    string operator[](int index);
    CreateIndex operator-(int index);
    CreateIndex operator--();
    CreateIndex operator--(int);
    operator string();
    CreateIndex operator!();
    bool operator>(CreateIndex);
    bool operator>=(CreateIndex);
    bool operator<(CreateIndex);
    bool operator<=(CreateIndex);
    bool operator==(CreateIndex);
};
CreateIndex::CreateIndex()
{

}

CreateIndex::CreateIndex(string name, string table, string column)
{
    this->name = name;
    this->table = table;
    this->column = column;
}

CreateIndex::CreateIndex(const CreateIndex& c)
{
    this->name = c.name;
    this->table = c.table;
    this->column = c.column;
}

CreateIndex::~CreateIndex()
{

}

string CreateIndex::getName()
{
    return this->name;
}

string CreateIndex::getTable()
{
    return this->table;
}

string CreateIndex::getColumn()
{
    return this->column;
}

void CreateIndex::setName(string name)
{
    this->name = name;
}

void CreateIndex::setTable(string table)
{
    this->table = table;
}

void CreateIndex::setColumn(string column)
{
    this->column = column;
}

CreateIndex CreateIndex::operator=(CreateIndex c)
{
    if (this == &c)
        return *this;
    this->name = c.name;
    this->table = c.table;
    this->column = c.column;
    return *this;
}

string CreateIndex::operator[](int index)
{
    switch (index)
    {
        case 0:
            return this->name;
            break;
        case 1:
            return this->table;
            break;
        case 2:
            return this->column;
            break;
        default:
            cout << "WRONG INPUT";
            throw  ExceptionPoo();
            break;
    }
}

CreateIndex CreateIndex::operator-(int index)
{
    CreateIndex c = *this;
    switch (index)
    {
        case 0:
            c.name = "";
            break;
        case 1:
            c.table = "";
            break;
        case 2:
            c.column = "";
            break;
        default:
            cout << "WRONG INPUT";
            throw  ExceptionPoo();
            break;
    }
    return c;
}

CreateIndex CreateIndex::operator--(int)
{
    CreateIndex c = *this;
    c.name = "";
    c.table = "";
    c.column = "";
    return c;
}

CreateIndex CreateIndex::operator--()
{
    CreateIndex c = *this;
    c.name = "";
    c.table = "";
    c.column = "";
    return c;
}

CreateIndex::operator string()
{
    return this->name + " " + this->table + " " + this->column;
}

CreateIndex CreateIndex::operator!()
{
    CreateIndex c = *this;
    c.name = "";
    c.table = "";
    c.column = "";
    return c;
}

bool CreateIndex::operator>(CreateIndex c)
{
    return this->name > c.name && this->table > c.table && this->column > c.column;
}

bool CreateIndex::operator>=(CreateIndex c)
{
    return this->name >= c.name && this->table >= c.table && this->column >= c.column;
}

bool CreateIndex::operator<(CreateIndex c)
{
    return this->name < c.name&& this->table < c.table&& this->column < c.column;
}

bool CreateIndex::operator<=(CreateIndex c)
{
    return this->name <= c.name && this->table <= c.table && this->column <= c.column;
}

bool CreateIndex::operator==(CreateIndex c)
{
    return this->name == c.name && this->table == c.table && this->column == c.column;
}


class DropIndex {
private:
    string name = "";
public:
    DropIndex(string name);
};
DropIndex::DropIndex(string name) {
    this->name = name;
    cout << "The Index " << this->name << " has been deleted!";
}

ostream& operator<<(ostream& out, const CreateIndex& c)
{
    out << "Index name: " << c.name << '\n'
        << "Table name: " << c.table << '\n'
        << "Column name: " << c.column << '\n';
    return out;
}

istream& operator>>(istream& in, CreateIndex& c)
{
    string name, table, column;
    cout << "Type index name: ";
    in >> name;
    cout << "Type table name: ";
    in >> table;
    cout << "Type column name: ";
    in >> column;
    c.setName(name);
    c.setTable(table);
    c.setColumn(column);
    return in;
}





class DropTable {
    string name = "";
public:


    DropTable(string name) {
        this->name = name;
        string filename = this->name + ".txt";
        ifstream fin(filename);
        if (!fin.is_open()) {
            cout << "The table " << this->name << " doesn't exist" << endl;
        }
        else

        {
            remove(filename.c_str());
            cout << "The Table " << this->name << " Has been deleted\n";
        }
    }




};
class doesFileExists {
public:
    bool CheckIfFileExists(string firstWord) {
        string filename = firstWord + ".txt";
        ifstream file(filename, ios::in);
        if (file.is_open()) {
            return 1;
        }
        return 0;
    }

};
class doesFileExistsBin {
public:
    bool CheckIfFileExists(string firstWord) {
        string filename = firstWord + ".bin";
        ifstream file(filename, ios::in);
        if (file.is_open()) {
            return 1;
        }
        return 0;
    }

};
class RemoveFile {
private:
    doesFileExists E;
public:
    void DeleteFile(string firstWord) {
        if (E.CheckIfFileExists(firstWord))
        {
            string filename = firstWord + ".txt";
            remove(filename.c_str());
            cout << "The file" << firstWord << ".txt has been removed" << endl;
        }
    }
};
class RemoveFileBin {
private:
    doesFileExistsBin E;
public:
    void DeleteFile(string firstWord) {
        if (E.CheckIfFileExists(firstWord))
        {
            string filename = firstWord + ".bin";
            remove(filename.c_str());
            cout << "The file" << firstWord << ".bin has been removed" << endl;
        }
    }
};
class Start {
    CreateTable* Tables = nullptr;
    int no = 1;
    string command = "";
public:
    void printOptions() {
        cout << "Here are the options: " << endl;
        cout << "IMPORT TABLE_NAME FILE_NAME.csv" << endl;
        cout << "CREATE TABLE name ((column,type,size,element))" << endl;
        cout << "CREATE INDEX index_name ON  table_name column_name" << endl;
        cout << "DROP TABLE table_name" << endl;
        cout << "DISPLAY TABLE table_name" << endl;
        cout << "INSERT INTO table_name VALUES (column,type,element)" << endl;
        cout << "DELETE FROM table_name WHERE column_name = value" << endl;
        cout << "SELECT ALL FROM table_name" << endl;
        cout << "UPDATE table_name SET new_column = new_element WHERE old_column = old_element" << endl;
        cout << "DROP INDEX index_name" << endl;
        cout << endl << "Write exit to close the app" << endl;
        cout << "-------------------------------------------------------" << endl;
    }
    void addWord(string* word, string wordToAdd, int noOfwords) {
        string* aux = new string[noOfwords + 1];
        for (int i = 0; i < noOfwords; i++)
        {
            aux[i] = word[i];

        }
        aux[noOfwords + 1] = wordToAdd;




    }
    void commandToUpper() {
        for (int i = 0; i < this->command.size(); i++)
            this->command[i] = toupper(this->command[i]);
    }
    string stringToLower(string a) {
        for (int i = 0; i < a.size(); i++)
            a[i] = tolower(a[i]);
        return a;

    }
    void convertInput() {

        int ok = 1;
        commandToUpper();
        stringstream words(this->command);
        if (this->command == "exit")
        {
            Start();
        }
        else {
            string firstWord;
            words >> firstWord;
            if (firstWord == "DISPLAY")
            {
                words >> firstWord;
                if (firstWord == "TABLE")
                {
                    firstWord = "";
                    words >> firstWord;
                    if (firstWord.empty())
                        cout << "Wrong Command, no parameters" << endl;

                    else
                    {
                        string aux = firstWord;
                        firstWord = "";
                        words >> firstWord;
                        if (firstWord.empty() == 0)
                        {
                            cout << "Wrong Command, number invalid of parameters" << endl;

                        }

                        else
                        {
                            /*tring name = firstWord;
                            doesFileExists E;
                            if (E.CheckIfFileExists(name) == 1)
                            {
                                cout << endl << "The data from the" << name << ".txt file is:" << endl;
                                string folder = name + ".txt";
                                ifstream file(folder, ios::in);
                                char buffer[100];
                                file.getline(buffer, 100);
                                cout << buffer << endl;
                                int size;
                                file >> size;
                                cout << size << endl;
                                for (int i = 0;i < 3 * size;i++) {
                                    char buffer[1000];
                                    file >> buffer;
                                    cout << buffer << endl;*/
                            doesFileExists D;
                            if (D.CheckIfFileExists(aux) == 0) {
                                cout << "File not found" << endl;
                            }
                            else {


                                cout << endl << "The data from the " << aux << " .txt file is: " << endl;
                                string folder = aux + ".txt";
                                ifstream file(folder, ios::in);
                                if (file.is_open())
                                {
                                    char buffer[100];
                                    file.getline(buffer, 100);
                                    cout << "Table: ";
                                    cout << buffer << endl;
                                    cout << "---------------------" << endl;
                                    cout << "Size: " << endl;
                                    string size;
                                    getline(file, size);
                                    cout << size << endl;
                                    cout << "Values:" << endl;
                                    for (int i = 0; i < stoi(size); i++) {

                                        string buffer[3];

                                        getline(file, buffer[0]);
                                        getline(file, buffer[1]);
                                        getline(file, buffer[2]);
                                        cout << buffer[0] << " <" << buffer[1] << "> " << buffer[2] << endl;




                                    }
                                    file.close();

                                }
                            }

                            /*bool ok = 0;
                            for (int i = 0; i < no; i++)
                            {
                                if (strcmp(Tables[i].getName(), aux.c_str()) == 0)
                                {
                                    DisplayTable d(Tables[i]); ok = 1;
                                    cout << endl;
                                    cout << "The info from the " << Tables[i].getName() << ".txt are:" << endl;
                                    ImportTxt E(Tables[i]);

                                }

                            }
                            if (ok == 0)cout << "The table does not exist in the database";*/
                        }
                    }






                }


            }
            else if (firstWord == "DROP")
            {
                words >> firstWord;
                if (firstWord == "TABLE")
                {
                    firstWord = "";
                    words >> firstWord;
                    doesFileExists E;
                    RemoveFile B;
                    if (E.CheckIfFileExists(firstWord) == 1)
                    {
                        B.DeleteFile(firstWord);
                        RemoveFileBin F;
                        F.DeleteFile(firstWord);
                        string fisier[100] = {};

                        ifstream file("names.txt", ios::in);
                        int z = 0;
                        if (file.is_open())
                            while (!file.eof()) {
                                getline(file, fisier[z]);
                                z++;
                            }

                        file.close();
                        ofstream files("names.txt", ios::out | ios::trunc);
                        if (files.is_open())
                        {
                            for (int i = 0; i < z - 1; i++)
                            {

                                if (fisier[i] != firstWord)
                                {

                                    files << fisier[i] << endl;
                                }


                            }
                            if (fisier[z - 1] != firstWord)
                                files << fisier[z - 1];
                        }

                        files.close();
                        // for (int i = 0; i < no; i++) {
                        //   Tables[i].setName(" ");
                        //}
                        delete[] Tables;
                        Tables = new CreateTable[no];


                    }
                    else cout << "There is no text file with this name" << endl;

                    if (firstWord.empty())
                        cout << "Wrong Command, no parameters" << endl;
                    else




                    {
                        string aux = firstWord;
                        firstWord = "";
                        words >> firstWord;
                        if (firstWord.empty() == 0)
                        {
                            cout << "Wrong Command, number invalid of parameters" << endl;

                        }
                        if (E.CheckIfFileExists(firstWord) == 1)
                        {
                            bool ok = 0;
                            for (int i = 1; i < no; i++)
                            {

                                if (strcmp(Tables[i].getName(), aux.c_str()) == 0)
                                {
                                    ok = 1;
                                    DropTable d(Tables[i].getName());

                                }
                            }




                            if (ok == 0)cout << "The table " << aux << " doesn't exist in the console database" << endl;


                        }
                    }
                }
                else
                if (firstWord == "INDEX")
                {
                    firstWord = "";
                    words >> firstWord;
                    if (firstWord == "")cout << "Wrong command.Try again";
                    else
                        DropIndex C(firstWord);
                }


            }
            else if (firstWord == "INSERT")
            {


                words >> firstWord;

                if (firstWord == "INTO") {
                    firstWord = "";
                    words >> firstWord;

                    if (firstWord.empty()) cout << "\nWrong command\n ";
                    else
                    {
                        string tableName = firstWord;
                        firstWord = "";


                        words >> firstWord;
                        if (firstWord.empty() || firstWord != "VALUES") cout << "\nWrong command\n ";
                        else {
                            firstWord = "";
                            getline(words, firstWord);

                            firstWord = firstWord.substr(firstWord.find("(") + 1,
                                                         firstWord.find_last_of(")") - firstWord.find("(") - 1);

                            stringstream s1(firstWord);
                            string data[10];
                            int k = 0;
                            while (getline(s1, data[k++], ',')) {
                                //  cout<<k<<endl;
                            }
                            //cout<<k<<endl;
                            if (k >= 5) {
                                cout << "You have passed to many arguments" << endl;
                                throw ExceptionPoo();
                            }
                            if (k < 4) {
                                cout << "You haven't passed enough arguments" << endl;
                                throw ExceptionPoo();
                            }
                            string fisier[100] = {};
                            string filename = tableName + ".txt";
                            ifstream fin(filename);
                            int z = 0;
                            while (!fin.eof()) {
                                getline(fin, fisier[z]);
                                z++;
                            }

                            fin.close();
                            ofstream fout(filename, ios::out | ios::trunc);
                            for (int i = 0; i < z - 1; i++)
                            {
                                if (i == 1)
                                {
                                    fout << stoi(fisier[i]) + 1 << endl;
                                }
                                else
                                    fout << fisier[i] << endl;
                            }
                            fout << fisier[z - 1];
                            fout.close();
                            doesFileExists E;
                            if (E.CheckIfFileExists(tableName) == 1)
                            {


                                ofstream file(filename, ios::out | ios::app);
                                if (file.is_open())
                                    for (int i = 0; i < 3; i++)
                                        file << data[i] << endl;
                                file.close();
                                cout << "The file " << tableName << " .txt has been altered" << endl;

                            }

                            else
                                cout << "The file" << tableName << ".txt does not exist" << endl;
                            //for(int i=0;i<k;i++)
                            //    cout<<endl<<data[i]<<endl;

                            //int ok = 0;
                            //for (int i = 1; i < no; i++)
                            //    if (strcmp(Tables[i].getName(), tableName.c_str()) == 0) {

                            //        cout << endl << "The INSERT function has been called for the table: ";
                            //        cout << tableName << " with the values: " << data[0] << ", " << data[1] << ", " << data[2] << endl;
                            //        InsertInto C(Tables[i], data[0], data[1], data[2]);
                            //        ExportTxt E(Tables[i]);
                            //        //ok = 1;
                            //        break;
                            //    }
                            //                        if (ok == 0)
                            //                            cout << "The table doesn't exist in the console database\n";
                            //                        if (firstWord.empty()) cout << "\nWrong command\n ";
                            //                        else
                            //                        {
                            //                            string column_name = firstWord;
                            //                            firstWord = "";
                            //
                            //
                            //                            words >> firstWord;
                            //
                            //                            if (firstWord.empty()) cout << "\nWrong command\n ";
                            //                            else
                            //                            {
                            //                                string type = firstWord;
                            //                                firstWord = "";
                            //
                            //                                words >> firstWord;
                            //
                            //                                if (firstWord.empty())
                            //                                    cout << "\nWrong command\n ";
                            //                                else {
                            //                                    string value = firstWord;
                            //
                            //                                    for (int i = 1; i < no; i++)
                            //                                        if (strcmp(Tables[i].getName(), tableName.c_str()) == 0) {
                            //
                            //                                            cout << endl << "The INSERT function has been called for the table: ";
                            //                                            cout<<tableName<<" with the values: "<<column_name<<", "<<type<<", "<<value<<endl;
                            //
                            //                                            InsertInto C(Tables[i], column_name, type, value);
                            //                                        }
                            //
                            //
                            //                                }
                            //
                            //
                            //                            }
                            //                        }
                        }

                    }


                }

            }
            else if (firstWord == "DELETE")
            {
                firstWord = "";
                bool ok = 0;
                words >> firstWord;
                if (firstWord == "FROM") {
                    firstWord = "";
                    words >> firstWord;

                    if (firstWord.empty()) cout << "Wrong command 4";
                    else
                    {
                        string tableName = firstWord;
                        firstWord = "";



                        words >> firstWord;
                        if (firstWord == "WHERE")
                        {
                            firstWord = "";
                            words >> firstWord;

                            string column_name = firstWord;
                            firstWord = "";
                            words >> firstWord;
                            if (firstWord == "=")
                            {
                                firstWord = "";
                                words >> firstWord;

                                string value = firstWord;
                                ifstream fin("names.txt");
                                if (fin.is_open())
                                {

                                    bool ok = false;
                                    string name;
                                    while (getline(fin, name)) {

                                        if (name == tableName)
                                        {

                                            ok = true;
                                            break;
                                        }
                                    }
                                    if (ok == true)
                                    {

                                        Delete T(tableName, column_name);
                                    }
                                }

                                //                            int j;
                                //                            for (int i = 1; i < no; i++)
                                //
                                //                                if (Tables[i].getName() == tableName) {
                                //                                    for (j = 0; j < Tables[i].getNoOfColumns(); j++)
                                //                                        if (Tables[i].getValues()[j] == value && Tables[i].getColumns()[j] == column_name)
                                //                                        {
                                //
                                //                                            Delete T(Tables[i], column_name);
                                //                                            j = Tables[i].getNoOfColumns() - 1;
                                //                                            ExportTxt E(Tables[i]);
                                //                                            cout << "The file" << Tables[i].getName() << ".txt" << " has been altered";
                                //                                        }
                                //
                                //
                                //                                }

                            }
                        }


                        cout << endl << "The DELETE function has been called" << endl;
                    }
                }
            }
            else if (firstWord == "SELECT")
            {
                firstWord = "";
                words >> firstWord;
                if (firstWord == "") cout << "Wrong command";
                else
                if (firstWord == "ALL")
                {
                    firstWord = "";
                    words >> firstWord;
                    if (firstWord != "FROM")cout << "Wrong command";
                    else
                    {
                        firstWord = "";
                        words >> firstWord;

                        if (firstWord == "")cout << "wrong command";
                        else
                        {
                            string name = firstWord;
                            doesFileExists E;
                            if (E.CheckIfFileExists(name) == 1)
                            {
                                cout << endl << "The data from the " << name << ".txt file is:" << endl;
                                string folder = name + ".txt";
                                ifstream file(folder, ios::in);
                                char buffer[100];
                                file.getline(buffer, 100);
                                cout << buffer << endl;
                                int size;
                                file >> size;
                                cout << size << endl;
                                for (int i = 0; i < 3 * size; i++) {
                                    char buffer[1000];
                                    file >> buffer;
                                    cout << buffer << endl;
                                }


                            }

                            for (int i = 1; i < no; i++)
                                for (int j = 0; j < Tables[i].getNoOfColumns(); j++)
                                {
                                    if ((Tables[i].getName()) == name) {
                                        DisplayTable c(Tables[i]);
                                        cout << endl << "The SELECT function has been called" << endl;
                                        break;
                                    }
                                }

                        }

                    }

                }
                //else  {
                //    firstWord = "";
                //    words >> firstWord;
                //        for (decltype(userString.size()) i = 0; i <= userString.size() - 1; i++)
                //            /* for(int i=0;i<vector[i].getNoOfColumns();i++)*/
                //        {
                //            if (std::find(userString.begin(), userString.end(), this->column) != userString.end())
                //                DisplayTable c(userString[i]);
                //            /* if (word == vector[i].getName())
                //                 DisplayTable c(vector[i]);*/
                //        }
                //    }







            }
            else if (firstWord == "IMPORT") {
                words >> firstWord;
                string tableName = firstWord;
                words >> firstWord;
                string fileName = firstWord;
                if (words.rdbuf()->in_avail() != 0)
                {
                    cout << "Too many arguments";
                    throw ExceptionPoo();
                }
                bool ok = 0;

                ifstream fin("names.txt");
                if (fin.is_open()) {
                    string name = "";
                    while (getline(fin, name)) {
                        if (name == tableName) {
                            ok = true;
                            break;
                        }
                    }
                }
                fin.close();
                if (ok == true) {
                    fileName = stringToLower(fileName);
                    ifstream inputCsv(fileName);
                    string txtname = tableName + ".txt";
                    ifstream fin(txtname);
                    int k = 0;
                    string values[10][3] = {};
                    string line = "";
                    while (getline(inputCsv, line)) {
                        stringstream inputcsv(line);
                        getline(inputcsv, values[k][0], ',');
                        getline(inputcsv, values[k][1], ',');
                        getline(inputcsv, values[k][2], ',');
                        //                    cout << values[k][0] << " " << values[k][1] << " " << values[k][2];
                        //                    cout << endl << k;
                        k++;
                    }
                    string fisier[100] = {};
                    int z = 0;
                    while (!fin.eof()) {
                        getline(fin, fisier[z]);
                        //cout << fisier[z] << " ";
                        z++;
                    }
                    cout << " k = " << k << endl;
                    fin.close();
                    ofstream fout(txtname, ios::out | ios::trunc);
                    for (int i = 0; i < z - 1; i++)
                    {
                        if (i == 1)
                        {
                            fout << stoi(fisier[i]) + k << endl;
                        }
                        else
                            fout << fisier[i] << endl;
                    }
                    fout << fisier[z - 1];
                    fout.close();
                    doesFileExists E;
                    if (E.CheckIfFileExists(tableName) == 1)
                    {


                        ofstream file(txtname, ios::out | ios::app);
                        if (file.is_open())
                            for (int j = 0; j < k; j++)
                                for (int i = 0; i < 3; i++)
                                    file << values[j][i] << endl;
                        file.close();
                        cout << "The file " << tableName << " .txt has been altered" << endl;

                    }
                }
                if (ok == 0)cout << "The table " << tableName << " doesn't exist" << endl;

            }
            else if (firstWord == "UPDATE")
            {
                firstWord = "";
                words >> firstWord;

                if (firstWord == "")cout << "invalid command";
                else {
                    string table_name = firstWord;
                    firstWord = "";
                    words >> firstWord;

                    if (firstWord != "SET")cout << "Invalid command";
                    else
                    {
                        firstWord = "";
                        words >> firstWord;

                        if (firstWord == "")cout << "Wrong command1";
                        else {
                            string column_name = firstWord;
                            firstWord = "";
                            words >> firstWord;

                            if (firstWord != "=")cout << "Wrong command2";

                            else
                            {
                                words >> firstWord;
                                string value = firstWord;
                                firstWord = "";
                                words >> firstWord;

                                if (firstWord != "WHERE")cout << "Wrong command3";
                                else
                                {
                                    words >> firstWord;
                                    string columnReplace = firstWord;
                                    firstWord = "";
                                    words >> firstWord;

                                    if (firstWord != "=")cout << "Wrong command4";

                                    else {
                                        words >> firstWord;
                                        string valueReplace = firstWord;
                                        /* doesFileExists E;
                                         RemoveFile B;
                                         if (E.CheckIfFileExists(firstWord) == 1)
                                         {
                                             B.DeleteFile(firstWord);
                                             string fisier[100] = {};

                                             ifstream file("names.txt", ios::in);
                                             int z = 0;
                                             if (file.is_open())
                                                 while (!file.eof()) {
                                                     getline(file, fisier[z]);
                                                     z++;
                                                 }

                                             file.close();
                                             ofstream files("names.txt", ios::out | ios::trunc);
                                             if (files.is_open())
                                             {
                                                 for (int i = 0; i < z - 1;i++)
                                                 {

                                                     if (fisier[i] != firstWord)
                                                     {

                                                         files << fisier[i] << endl;
                                                     }


                                                 }
                                                 if (fisier[z - 1] != firstWord)
                                                     files << fisier[z - 1];
                                             }

                                             files.close();*/
                                        doesFileExists E;
                                        if (E.CheckIfFileExists(table_name) == 1)
                                        {
                                            int z = 0;
                                            string folder = table_name + ".txt";
                                            string text[100] = { "" };
                                            ifstream file(folder, ios::in);
                                            if (file.is_open())
                                                while (!file.eof()) {

                                                    getline(file, text[z]);
                                                    z++;



                                                }
                                            else
                                                cout << "Something is wrong with the file";
                                            file.close();
                                            ofstream files(folder, ios::out | ios::trunc);
                                            if (files.is_open())
                                            {

                                                files << text[0] << endl << text[1] << endl;

                                                for (int i = 2; i < z - 1; i += 3)
                                                    if (text[i] != columnReplace && text[i + 2] != valueReplace)
                                                        files << text[i] << endl << text[i + 1] << endl << text[i + 2] << endl;
                                                    else
                                                        files << column_name << endl << text[i + 1] << endl << value << endl;
                                                cout << "The update function has been called for " << folder;

                                            }

                                        }

                                        else

                                            for (int i = 1; i < no; i++)
                                                if (Tables[i].getName() == table_name)
                                                {
                                                    for (int j = 0; j < Tables[i].getNoOfColumns(); j++)
                                                    {

                                                        if (Tables[i].getColumns()[j] == columnReplace && Tables[i].getValues()[j] == valueReplace)
                                                        {
                                                            cout << endl << "UPDATE function has been called" << endl;
                                                            cout << endl;
                                                            Tables[i].getColumns()[j] = column_name;


                                                            Tables[i].getValues()[j] = value;
                                                            ExportTxt E(Tables[i]);
                                                            cout << "The file " << Tables[i].getName() << ".txt has been altered" << endl;

                                                        }


                                                    }
                                                    i = no - 1;
                                                }
                                    }
                                }

                            }
                        }
                    }


                }

            }
            else if (firstWord == "CREATE")
            {
                words >> firstWord;
                if (firstWord == "TABLE") {
                    words >> firstWord;
                    bool isAlreadyCreated = 0;
                    for (int i = 1; i < no; i++)
                    {
                        if (Tables[i].getName() == firstWord) isAlreadyCreated = 1;

                    }
                    doesFileExists E;
                    if (E.CheckIfFileExists(firstWord) == 1) cout << "File " << firstWord << ".txt already exists" << endl;
                    else
                    if (isAlreadyCreated == 1) cout << "The table already exists";
                    else
                    {
                        string tableName = firstWord;
                        string s1;
                        getline(words, s1);
                        //cout<<"~"<<s1<<"~\n";
                        //                int k = 0;
                        //                while (words >> firstWord) {
                        //                    data[k++] = firstWord;
                        //                }
                        string token = s1.substr(s1.find("(") + 1, s1.find_last_of(")") - 1);
                        s1 = token;
                        int c = 0;
                        string data[10][10];
                        //cout<<token<<endl;
                        while (s1[0] == '(')
                        {
                            c++;
                            int k = 0;
                            token = s1.substr(s1.find("(") + 1, s1.find(")") - 1);
                            //cout<<token<<endl;
                            stringstream s2(token);
                            while (getline(s2, data[c][k++], ',')) {
                                //cout<<data[c][k-1]<<endl;
                            }
                            if (s1.find(")") + 2 < s1.find_last_of(")"))
                            {
                                s1 = s1.substr(s1.find(")") + 2, s1.find_last_of(")"));
                                s1 = s1.substr(s1.find("("), s1.find_last_of(")"));
                                //cout<<s1<<endl;
                                //token=s1.substr(s1.find("("),s1.find(")"));
                                //cout<<" "<<token<<endl;
                            }
                            else
                                break;
                        }
                        if (!tableName.find("(") or !tableName.find(")") or !tableName.find(","))
                        {
                            cout << "N ai scris bine" << endl;
                            throw ExceptionPoo();
                        }
                        //                for(int i=1;i<=c;i++)
                        //                {for(int j=0;j<4;j++)
                        //                        cout<<data[i][j]<<" ";
                        //                    cout<<endl;
                        //                }
                        CreateTable* newTables = new CreateTable[no];
                        if (Tables != nullptr) {
                            for (int i = 0; i < no; i++)
                            {
                                newTables[i] = Tables[i];
                            }
                            delete[] Tables;
                        }
                        no++;
                        Tables = new CreateTable[no];
                        for (int i = 0; i < no - 1; i++)
                        {
                            Tables[i] = newTables[i];
                        }
                        CreateTable temp(tableName.c_str());
                        Tables[no - 1] = temp;
                        for (int i = 1; i <= c; i++)
                            Tables[no - 1].addColumn(data[i][0], data[i][1], data[i][3]);
                        cout << endl << "The table " << tableName << " has been created" << endl;
                        //cout<<Tables[no-1].getName();
                        //CreateTable C(data[0].c_str());
                        //Tables[no - 1].addColumn(data[1], data[2], data[3]);
                        DisplayTable D(Tables[no - 1]);
                        D.~DisplayTable();

                        ExportTxt E(Tables[no - 1]);
                        string filen = string(Tables[no - 1].getName()) + ".bin";
                        string filen1 = string(Tables[no - 1].getName()) + ".txt";
                        ofstream fbin(filen, ios::out | ios::trunc | ios::binary);
                        ifstream fin(filen1);
                        if (fbin.is_open() && fin.is_open()) {
                            fbin.write(Tables[no - 1].getName(), sizeof(Tables[no - 1].getName()));
                            //fbin.write((char*)&Tables[no - 1].getNoOfColumns(), sizeof(int));
                            string buffer = "";
                            getline(fin, buffer);

                            getline(fin, buffer);
                            fbin.write((char*)&buffer, buffer.size() * sizeof(char));

                            if (stoi(buffer) > 0) {
                                int number = stoi(buffer);
                                for (int i = 0; i < number; i++) {
                                    string buffer[3];
                                    getline(fin, buffer[0]);
                                    getline(fin, buffer[1]);
                                    getline(fin, buffer[2]);
                                    fbin.write((char*)&buffer[0], buffer[0].size() * sizeof(char));
                                    fbin.write((char*)&buffer[1], buffer[1].size() * sizeof(char));
                                    fbin.write((char*)&buffer[2], buffer[2].size() * sizeof(char));

                                }
                            }


                        }
                        ofstream f("names.txt", ios::out | ios::app);
                        f << Tables[no - 1].getName() << endl;
                        f.close();
                        E.~ExportTxt();

                        //cout<<"~"<<data[2]<<" "<<data[4]<<" "<<data[6]<<endl;
                        //cout << Tables[no-1].getName() << endl << C.getColumns() << endl << C.getColumns() << " " << C.getTypes() << " " << C.getValues() << endl;
                    }
                }
                if (firstWord == "INDEX")
                {




                    string indexName, on, indexTable, indexColumn;
                    words >> indexName >> on >> indexTable >> indexColumn;
                    firstWord = "";
                    words >> firstWord;

                    if (firstWord == "" && on == "ON")
                    {
                        CreateIndex c(indexName, indexTable, indexColumn);
                        cout << c;
                        cout << endl << "The CREATE INDEX function has been called" << endl;
                    }
                    else
                    {
                        cout << "Wrong command";
                    }
                }
            }
            else if (firstWord != "exit") {

                cout << "Your input isn't correct" << endl;

            }
            ok = 0;
        }
        if (ok == 0)
        {
            cout << "Insert another command" << endl;
            cout << "-------------------------------------------------------" <<endl;
            printOptions();

        }
        else
        {
            Start();
        }
    }
    Start() {
        printOptions();
        cout << "Write your command ..." << endl;
        while (getline(cin, command))
        {

            if (command == "exit")
                break;

            convertInput();
        }
    }
    Start(string docName) {
        ifstream fin(docName);
        while (getline(fin, this->command))
        {

            if (this->command == "exit")
                break;
            convertInput();
        }

    }




};

