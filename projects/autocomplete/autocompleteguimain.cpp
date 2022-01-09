/*
 * File: autocompleteguimain.cpp
 * -----------------
 * GUI program for project 3 - Autocomplete.
 * 
 * Place your WordCount and CountList files in the same directory as this 
 * file. This file will use them to pop up a window with a search box the
 * user can type in. As the user types, the suggested autocomplete options below
 * it will change so that they are always valid for the current text.
 * 
 * Make sure that all of your functions work correctly with your non-graphical 
 * main before running this!
 * 
 * WARNING: You will have build errors if you have more than one one file with
 * a main in the same project. To fix this, change the name of the main in the
 * file you are not currently running to something else. 
 */

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "console.h"
#include "gwindow.h"
#include "gtextfield.h"
#include "glabel.h"
#include "gtextarea.h"

#include "WordCount.h"
#include "CountList.h"

using namespace std;
using namespace sgl;

GTextField* textbox;
GTextArea* area;
CountList counts;


// takes a vector of strings as a parameter and returns a string representation
// of its contents with one string per line. 
string format(vector<WordCount> suggestions) {
    string result = "";
    for(WordCount current : suggestions) {
        result += current.getPhrase() += "\t" +=  current.getCount() += "\n";
    }
    return result;
}

// replaces the suggested autocomplete options in the text area with new
// autocomplete options whenever the user alters the contents of the textbox
void recomputeList() {
    string text = textbox->getText();
    string suggestions = format(counts.getStartingWith(text, 10));
    area->setText(suggestions);
}

int main() {
    // get file name from user
    cout << "Dictionary file? ";
    string fileName;
    cin >> fileName;

    // initialize the GUI window settings
    GWindow* window = new GWindow(500, 250);
    window->setTitle("Autocomplete");
    window->setLocation(400, 200);
    window->setExitOnClose(true);
    window->setColor("black");

    // initialize the CountList with the data from the file
    // get the top 10 suggestions back and format for display
    counts = CountList(fileName);
    string suggestions = format(counts.getTop(10));
    
    // create the search box and set it to call recomputeList when the text in 
    // it changes
    GLabel* prompt = new GLabel("Search phrase:");
    textbox = new GTextField("", 20);
    textbox->setTextChangeListener(recomputeList);

    // initialize the box that will hold suggestions and set it to initially 
    // hold the most common words from the dictionary
    area = new GTextArea();
    area->setText(suggestions);

    // add all components to the GUI window and make it visible
    window->addToRegion(prompt, "North");
    window->addToRegion(textbox, "North"); 
    window->addToRegion(area, "Center");
    window->setVisible(true);
    return 0;
}