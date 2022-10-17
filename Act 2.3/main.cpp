// =================================================================
//
// File: main.cpp
// Author: Santiago Rodriguez Murialdo & Gamaliel Marines
// Date: 10/17/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include "sstream"

using namespace std;

class Outs{
    public:
        string month, id, sea;
        int num;
};


vector<string> readLines(string filename){
    vector<string> lines;
    ifstream file(filename);
    string line;
    while(getline(file, line)){
        lines.push_back(line);
    }
    return lines;
}

vector<string> split(string line){
    vector<string> words;
    string word;
    for(int i=0; i<line.length(); i++){
        if(line[i] == ' '){
            words.push_back(word);
            word = "";
        }
        else{
            word += line[i];
        }
    }
    words.push_back(word);
    return words;
}

vector<string> filter(vector<string> lines, string word){
    vector<string> filteredLines;
    for (string line : lines){
        if(line.find(word) != string:: npos)
            filteredLines.push_back(line);
    }
    return filteredLines;
}

vector<string> sortLines(vector<string> lines){
	sort(lines.begin(), lines.end(), [](string a, string b) {
		vector<string> aSplit;
		vector<string> bSplit;
		string delimiter = "-";
		size_t pos = 0;
		string token;
		while ((pos = a.find(delimiter)) != string::npos) {
			token = a.substr(0, pos);
			aSplit.push_back(token);
			a.erase(0, pos + delimiter.length());
		}
		aSplit.push_back(a);
		while ((pos = b.find(delimiter)) != string::npos) {
			token = b.substr(0, pos);
			bSplit.push_back(token);
			b.erase(0, pos + delimiter.length());
		}
		bSplit.push_back(b);
		return pair<string, string>(aSplit[1], aSplit[0]) < 
		pair<string, string>(bSplit[1], bSplit[0]);
	});
    return lines;
}
vector<Outs> month(vector<string> sortedLines){
    vector<Outs> Output;

    for (int i=0; i<sortedLines.size(); i++){
        string month = sortedLines[i].substr(3,2);
        Outs OUT;
        if (month == "01"){
            sortedLines[i].replace(3,2,"jan");
            OUT.month = "jan";
        }
        else if (month == "02"){
            sortedLines[i].replace(3,2,"feb");
            OUT.month = "feb";
        }
        else if (month == "03"){
            sortedLines[i].replace(3,2,"mar");
            OUT.month = "mar";
        }
        else if (month == "04"){
            sortedLines[i].replace(3,2,"apr");
            OUT.month = "apr";
        }
        else if (month == "05"){
            sortedLines[i].replace(3,2,"may");
            OUT.month = "may";
        }
        else if (month == "06"){
            sortedLines[i].replace(3,2,"jun");
            OUT.month = "jun";
        }
        else if (month == "07"){
            sortedLines[i].replace(3,2,"jul");
            OUT.month = "jul";
        }
        else if (month == "08"){
            sortedLines[i].replace(3,2,"aug");
            OUT.month = "aug";
        }
        else if (month == "09"){
            sortedLines[i].replace(3,2,"sep");
            OUT.month = "sep";
        }
        else if (month == "10"){
            sortedLines[i].replace(3,2,"oct");
            OUT.month = "oct";
        }
        else if (month == "11"){
            sortedLines[i].replace(3,2,"nov");
            OUT.month = "nov";
        }
        else if (month == "12"){
            sortedLines[i].replace(3,2,"dec");
            OUT.month = "dec";
        }
        OUT.id = sortedLines[i].substr(18,5);
        OUT.sea = sortedLines[i].substr(16,1);
        Output.push_back(OUT);
    }
    return Output;
}
string output(vector<string> sortedLines){
    vector<Outs> Output = month(sortedLines);
    int countM = 0, countR = 0, countMonth = 0, count = 0;
    vector<string> ubisM, ubisR;
    stringstream outputLine;

    //JAN//
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "jan"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "jan" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //FEB//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "feb"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[count+i].id);
            }else{
                countR++;
                ubisR.push_back(Output[count+i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "feb" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //MAR//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "mar"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "mar" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //ABR//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "apr"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "apr" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //MAY//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "may"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "may" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //JUN//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "jun"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "jun" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //JUL//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "jul"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "jul" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //AUG//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "aug"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "aug" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //SEP//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "sep"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "sep" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //OCT//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "oct"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "oct" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;

    //NOV//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "nov"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "nov" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;


    //DEC//
    count = countM + countR;
    countM = 0; countR = 0; countMonth = 0;
    ubisM.clear(); ubisR.clear();
    for(int i = 0; i < Output.size(); i++){
        if(Output[i].month == "dec"){
            if (Output[i].sea == "M"){
                countM++; 
                ubisM.push_back(Output[i].id);
            }else{
                countR++;
                ubisR.push_back(Output[i].id);
            }
            countMonth++;
        }
    }
    if(countMonth > 0){
        outputLine << "dec" << endl;
        if (countM > 0){
            outputLine << "M " << countM << ": ";
            for(int w=0; w < countM; w++){
                outputLine << ubisM[w] << " ";
            }
        }
        outputLine << endl;
        if (countR > 0){
            outputLine << "R " << countR << ": ";
            for(int w=0; w < countR; w++){
                outputLine << ubisR[w] << " ";
            }
        }
    }
    outputLine << endl;
    return outputLine.str();
}

int main(int argc, char* argv[]) {

	ifstream InputFile;
	ofstream OutputFile;

    if(argc != 3){
		cout << "Invocacion Incorrecta!" << endl;
		return -1;
	}
	InputFile.open(argv[1]);
	if(InputFile.fail()){
		cout << "No se puede abrir el archivo de entrada" << endl;
		return -1;
	}
	OutputFile.open(argv[2]);
	if(OutputFile.fail()){
		cout << "No se puede abrir el archivo de salida" << endl;
		return -1;
	}

    vector<string> lines = readLines(argv[1]);
    vector<string> words = split(lines[0]);
    vector<string> filteredLines = filter(lines, words[1]);
                   filteredLines.erase(filteredLines.begin());
    vector<string> sortedLines = sortLines(filteredLines);

    
    OutputFile <<output(sortedLines);

    
}