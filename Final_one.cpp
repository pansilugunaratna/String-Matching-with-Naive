//----------------------STRING MATCHING-------------------------------------------

/* Constraints :
	Text does not include any symbols including underscores
	Text does not include any spaces
*/
#include <iostream>
#include <string>
#include <fstream> //stream class to both read and write
using namespace std;
 
int write_output(int shift, string file_out){
	ofstream output;
	output.open(file_out.c_str(), std::ios_base::app);
	string text = "------------------\nMatch found at ";
    output << text << shift << endl;
    output.close();
}

string string_match(string text_txt, string pattern_txt, string file_out){
	
	////------------------------Read and display the text files----------------------------------
	string TEXT = "", PATTERN = "";
	
	ifstream textfile, patternfile;
	string text_line,pattern_line;
	textfile.open (text_txt.c_str());
	patternfile.open (pattern_txt.c_str());
	
	cout << "____________________________________" << endl;
	if (textfile.is_open() && patternfile.is_open()){
		cout << "text: ";
	    while ( getline (textfile,text_line) ){
	    	TEXT.append(text_line);		//Append the text letters in to the variable TEXT
	    	//cout << text_line << '\n';
	    }
	    cout << TEXT << endl;
	    textfile.close();
	    
	    cout << "pattern: ";   
	    while ( getline (patternfile,pattern_line) ){
	    	PATTERN.append(pattern_line);		//Append the text letters in to the variable PATTERN
	    	//cout << pattern_line << '\n';
	    }
	    cout << PATTERN << endl;
	    patternfile.close();
	  }
	
	else 
		cout << "File Not Found! Try again" << endl; 
	cout << "____________________________________" << endl;
	
	
	//------------------------Naive String Matching----------------------------------
	
	int shift,m;
	int T = TEXT.size();
	int P = PATTERN.size();
	
	for(shift=0; shift<=(T-P); shift++){  //shift
		for(m=0; m<P; m++){		//m is the index of the pattern checked with the text 
			if(PATTERN[m] == '_')	//check whether the letter is replaced with an underscore
				continue;
			if(TEXT[shift+m] != PATTERN[m])
				break;
		}		
		if(m == P)
			write_output(shift+1,file_out);
	}		
}

int main(){
	string text,pattern,out;
	
	cout << "Text Files: text1.txt, text2.txt, text3.txt, text4.txt, text5.txt" << endl;
	cout << "Pattern Files: pattern1.txt, pattern2.txt, pattern3.txt, pattern4.txt, pattern5.txt" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "Enter text filename with the extension: " ;
	cin >> text ;
	cout << "Enter pattern filename with the extension: " ;
	cin >> pattern ;
	cout << "Enter a name for the output file with the extension .output: " ;
	cin >> out ;
	
//Clear any previous data of the file	
	std::ofstream output;
	output.open(out.c_str(), std::ofstream::out | std::ofstream::trunc);
	output.close();
	
	string_match(text, pattern, out);
	
	return 0;
}
