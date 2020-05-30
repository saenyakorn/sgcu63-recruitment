#include <vector>

using namespace std;

typedef vector<char> vc;

char number_template[10][5][5] = {
    // number zero
    {
        {'0', '0', '0', '0', '0'},
        {'0', ' ', ' ', ' ', '0'},
        {'0', ' ', ' ', ' ', '0'},
        {'0', ' ', ' ', ' ', '0'},
        {'0', '0', '0', '0', '0'}},
    // number one
    {
        {' ', ' ', ' ', ' ', '1'},
        {' ', ' ', ' ', ' ', '1'},
        {' ', ' ', ' ', ' ', '1'},
        {' ', ' ', ' ', ' ', '1'},
        {' ', ' ', ' ', ' ', '1'}},
    // number two
    {
        {'2', '2', '2', '2', '2'},
        {' ', ' ', ' ', ' ', '2'},
        {'2', '2', '2', '2', '2'},
        {'2', ' ', ' ', ' ', ' '},
        {'2', '2', '2', '2', '2'}},
    // number three
    {
        {'3', '3', '3', '3', '3'},
        {' ', ' ', ' ', ' ', '3'},
        {'3', '3', '3', '3', '3'},
        {' ', ' ', ' ', ' ', '3'},
        {'3', '3', '3', '3', '3'}},
    // number four
    {
        {'4', ' ', ' ', ' ', '4'},
        {'4', ' ', ' ', ' ', '4'},
        {'4', '4', '4', '4', '4'},
        {' ', ' ', ' ', ' ', '4'},
        {' ', ' ', ' ', ' ', '4'}},
    // number five
    {
        {'5', '5', '5', '5', '5'},
        {'5', ' ', ' ', ' ', ' '},
        {'5', '5', '5', '5', '5'},
        {' ', ' ', ' ', ' ', '5'},
        {'5', '5', '5', '5', '5'}},
    // number six
    {
        {'6', '6', '6', '6', '6'},
        {'6', ' ', ' ', ' ', ' '},
        {'6', '6', '6', '6', '6'},
        {'6', ' ', ' ', ' ', '6'},
        {'6', '6', '6', '6', '6'}},
    // number seven
    {
        {'7', '7', '7', '7', '7'},
        {' ', ' ', ' ', ' ', '7'},
        {' ', ' ', ' ', ' ', '7'},
        {' ', ' ', ' ', ' ', '7'},
        {' ', ' ', ' ', ' ', '7'}},
    // number eight
    {
        {'8', '8', '8', '8', '8'},
        {'8', ' ', ' ', ' ', '8'},
        {'8', '8', '8', '8', '8'},
        {'8', ' ', ' ', ' ', '8'},
        {'8', '8', '8', '8', '8'}},
    // number nine
    {
        {'9', '9', '9', '9', '9'},
        {'9', ' ', ' ', ' ', '9'},
        {'9', '9', '9', '9', '9'},
        {' ', ' ', ' ', ' ', '9'},
        {'9', '9', '9', '9', '9'}},
};