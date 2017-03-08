//
//  align.cpp
//  dna_alignment
//
//  Created by Erika DeBenedictis on 1/27/13.
//  Copyright (c) 2014 California Institute of Technology. All rights reserved.
//
#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

// scoring values
#define GAP_SCORE -5
#define MISMATCH -1
#define MATCHING 2

/**
 * @brief Packages the score and instruction string the align function returns
 */
struct align_result {
    int score;      // score of this alignment
    string inst;    // instruction on how to align the inputs

    align_result(int s, string i) {
        this->score = s;
        this->inst = i;
    }
    align_result() {
        this->score = 0;
        this->inst = "";
    }
};

// memo_type will allow us to hash the string input to align
// with its output for memoization
typedef unordered_map<string, align_result> memo_type;

/**
 * @brief Function takes two strings, s and t, and produces an align_result
 * of the highest alignment score and its corresponding instruction str.
 */
// Helper function to return max of three integers
 int maximum(int x, int y, int z) {
	int max = x; 
	
	if (z > max) { 
		max = z;
	} 
	if (y > max) {
		max = y;
	} 



	return max; 
}

align_result align(string s, string t, memo_type &memo) {
    // if this result is memoized, use recorded result
    align_result answer;


    string key = s + "," + t;
    if (memo.count(key) > 0){
      return memo[key];
    }


    if (s.size() == 0 && t.size() == 0)
    {
    	answer = align_result();
    }

    else if (s.size() == 0){

    	answer = align_result(GAP_SCORE*t.size(), string(t.size(), 't'));
    }

    else if (t.size() == 0){

    	answer = align_result(GAP_SCORE*s.size(), string(s.size(),'s'));
    }

    else {
    	align_result gapS = align(s, t.substr(0,t.size()-1), memo);
    	gapS.score += GAP_SCORE;
    	gapS.inst += "t";
    	align_result gapT = align(s.substr(0,s.size()-1),t, memo);
		gapT.score += GAP_SCORE;
		gapT.inst += "s";
		align_result match_mismatch;

		if (s.at(s.size()-1) == t.at(t.size()-1))
		{

			match_mismatch = align(s.substr(0,s.size()-1), t.substr(0,t.size()-1), memo);
			match_mismatch.score += MATCHING;
			
			match_mismatch.inst += "|";

		}

		else
		{
			
			match_mismatch = align(s.substr(0,s.size()-1), t.substr(0,t.size()-1), memo);
			match_mismatch.score += MISMATCH;
			match_mismatch.inst += "*";

		}

		
		int max1 = maximum(gapT.score, gapS.score, match_mismatch.score);

		if (gapT.score == max1){
			answer = gapT;
		}

		else if (gapS.score == max1){
			answer = gapS;
		}

		else {
			answer=  match_mismatch;
		}
    }


    
    memo[key] = answer;
    return answer;
}





/**
 * @brief Wrapper function to print the results of align
 */
void DNA_align(string s, string t) {
    cout << endl << "Calling DNA align on strings " << s << ", " << t << endl;

    // create the memoization system
    memo_type memo;

    align_result answer = align(s, t, memo);
    string ans = answer.inst;

    // Printing section
    // line where string s will be printed, spaces inserted
    string line1 = "";
    // line where string t will be printed, spaces inserted
    string line2 = "";
    // description of the relationship between s and t here (* | s t)
    string line3 = "";

    int j = 0;      // running index in s
    int k = 0;      // running index in t

    for (unsigned int m = 0; m < ans.length(); m++) {
        // i is the next element in our instruction string ans
        string i = ans.substr(m, 1);

        // only in s
        if(i.compare("s") == 0){
            line1 += s[j]; j++;
            line2 += " ";
            line3 += "s";
        }

        // only in t
        else if (i.compare("t") == 0){
            line1 += " ";
            line2 += t[k]; k++;
            line3 += "t";
        }

        // mismatch
        else if (i.compare("*") == 0){
            line1 += s[j]; j++;
            line2 += t[k]; k++;
            line3 += "*";
        }

        // match
        else {
            line1 += s[j]; j++;
            line2 += t[k]; k++;
            line3 += "|";
        }
    }
    cout << line1 << endl << line2 << endl << line3 << endl;
}

int main(){
    // some test cases to begin with
    DNA_align("",   "a");
    DNA_align("b",  "");
    DNA_align("a", "a");
    DNA_align("b",  "a");
    DNA_align("b",  "ba");
    DNA_align("ab", "ba");
    DNA_align("ab", "b");
    DNA_align("abc", "adc");
    DNA_align("abc", "ac");
    DNA_align("abc", "c");
    DNA_align("abracadabra", "avada kedavra");
    DNA_align("TCAGTCGAAATGAATGCCCCTAATTATCACTATGAGGAATGCTCCTGTTATCCTGATTCTAGTGAAATCACATGTGTGTGCAGGGATAACTGGCATGGCTCGAATCGACCGTGGGTGTCTTTCAACCAGAATCTGGAATATCAGATAGGATACATATG",
    	"GTAATGACCGATGGACCAAGTGATGGACAGGCCTCATACAAGATCTTCAAAATAGAAAAGGGAAAGATAGTCAAATCAGTCGAGATGAATGCCCCTAATTATCACTATGAGGAATGCTCCTGTTATCCTGATTCTAGTGAAATCACA");
    return 0;
}

