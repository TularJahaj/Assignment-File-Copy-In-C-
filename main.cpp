#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    /*
     * argv[0] is the programm name itself
     */
    if(argc!=3) {
        cout << "need two argument"<<endl;
        return 0;
    }

    char* infile = argv[1];
    char* outfile = argv[2];

    try{
        FILE *in = fopen(infile, "r");
        FILE *out = fopen(outfile, "w");

        if(in == NULL) {
            perror(infile);
            return 0;
        }

        cout<<"Copying from "<<infile<<" to "<<outfile<<"......"<<endl;

        char buf[1024];
        int read = 0;

        //  Read data in 1kb chunks and write to output file
        while ((read = fread(buf, 1, 1024, in)) == 1024)
        {
            fwrite(buf, 1, 1024, out);
        }

        //  If there is any data left over write it out
        fwrite(buf, 1, read, out);

        fclose(out);
        fclose(in);
    }catch (exception e){
        perror(e.what());
    }
    return 0;
}