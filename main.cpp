#include<iostream>
#include<vector>
#include<fstream>
#include"pixel.h"


void average_colors(std::vector<Pixel> &pixel_list){

	int size = pixel_list.size();
	
	float r_avg = 0;
	float g_avg = 0;
	float b_avg = 0;

	for (int i = 0; i < size; i++){


		r_avg += pixel_list[i].r; 
		g_avg += pixel_list[i].g;
		b_avg += pixel_list[i].b; 
	}

	r_avg /= size;
	g_avg /= size;
	b_avg /= size;
	
	std::cout << "- - - - - - Average of R, G, and B - - - - - -" << std::endl;

	std::cout << "R Average: " << r_avg << std::endl << "G Average: " << g_avg << std::endl << "B Average: " << b_avg << std::endl;

}


Pixel make_pixel(std::string& line){
	
	Pixel pixel;
	int pos;
	pos = line.find(',');

	pixel.x = stoi(line.substr(0, pos));
	line = line.substr(pos+1);

	pos = line.find(',');
       	pixel.y = stoi(line.substr(0, pos));
	line = line.substr(pos+1);

	pos = line.find(',');
       	pixel.r = stof(line.substr(0, pos));
	line = line.substr(pos+1);

	pos = line.find(',');
	pixel.g = stof(line.substr(0, pos));
	line = line.substr(pos+1);

	pixel.b = stof(line);
	
	return pixel;


}

void flip_vertically(std::vector<Pixel>&pixel_list){
	
	int size = pixel_list.size();

	for (int i = 0; i < size; i++)
	{

		pixel_list[i].y = (size - 1) - (pixel_list[i].y);

	}

	std::ofstream file("flipped.dat");

    	if (!file.is_open()) {
        	std::cout << "Could not open file for writing!\n";
        	return;
   	 }


	for (const auto& p : pixel_list) {
    		file << p.x << "," << p.y << "," << p.r << "," << p.g << "," << p.b << std::endl;
	}
	
	std::cout << "Successfully wrote to flipped.dat\n" << std::endl;

	file.close();
}


int main(int argc, char* argv[]){

	std::vector<Pixel>pixel_list;
	std::string line;
	std::ifstream file(argv[1]);

	if (file.is_open()){ 
		
		std::cout << "Successfully opened file " << argv[1] << "\n" << std::endl;
		
		while(getline(file, line)){
		
			pixel_list.push_back(make_pixel(line));
		}

		file.close();
			
	}

	else {

		std::cout << "No source file found... Terminating..." << std::endl;
		return 1;
	}


	
	flip_vertically(pixel_list);
	
	average_colors(pixel_list);

}
