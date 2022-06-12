#include <fstream>
#include <iostream>
#include "main.h"
#include "renderer.h"
#include "cmath.h"

using namespace std;

int main(int argc, char *argv[])
{
    int width, height;
    parseCmd(argc, argv, width, height);
    Renderer renderer = Renderer(width, height);

    cout << renderer;
}

/**
 * @brief Parses command line arguments for determining the width and height of the canvas.
 *
 * @param argc The number of arguments passed in.
 * @param argv The passed in arguments.
 * @param w The OUT width value.
 * @param h The OUT height value.
 */
void parseCmd(int argc, char *argv[], int &w, int &h)
{
    w = 500;
    h = 500;
    if (argc > 2)
    {
        try
        {
            w = stoi(argv[1]);
        }
        catch (invalid_argument &excp)
        {
            cout << "Expected a number for the width. Set to 500" << endl;
        }
        catch(out_of_range &excp){
            cout << "Width was too big for stoi to handle. Set to 500" << endl;
        }
        if (w < 0 || w > 1200)
        {
            cout << "Expected a positive number less than 1201 for the width. Set to 500" << endl;
            w = 500;
        }


        try
        {
            h = stoi(argv[2]);
        }
        catch (invalid_argument &excp)
        {
            cout << "Expected a number for the height. Set to 500" << endl;
        }
        catch(out_of_range &excp){
            cout << "Height was too big for stoi to handle. Set to 500" << endl;
        }        
        if (h < 0 || h > 1200)
        {
            cout << "Expected a positive number less than 1201 for the height. Set to 500" << endl;
            h = 500;
        }
    }
}