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
	
	std::cout << "Test" << std::endl;

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
	
	std::cout << pixel.x << std::endl;
	std::cout << pixel.y << std::endl;
	std::cout << pixel.r << std::endl;
	std::cout << pixel.g << std::endl;
	std::cout << pixel.b << std::endl;

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
    		file << p.x << "," << p.y << "," << p.r << "," << p.g << "," << p.b << "\n";
	}

	file.close();
}


int main(int argc, char* argv[]){

	std::vector<Pixel>pixel_list;
	std::string line;
	std::ifstream file(argv[1]);

	if (file.is_open()){ 
		
		std::cout << "Opened file " << argv[1] << std::endl;
		
		while(getline(file, line)){
		
			std::cout << argv[1] << std::endl;
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

	for (int i = 0; i < pixel_list.size(); i++) {
    		std::cout << "x: " << pixel_list[i].x << ", y: " << pixel_list[i].y << ", r: " << pixel_list[i].r << ", g: " << pixel_list[i].g << ", b: " << pixel_list[i].b << std::endl;
	}
	std::cout << "Number of pixels loaded: " << pixel_list.size() << std::endl;

}
