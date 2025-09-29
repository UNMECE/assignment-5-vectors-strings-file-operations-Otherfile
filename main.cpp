#include<stdio.h>
#include<stdlb.h>

Pixel make_pixel(std::string& line){
	
	Pixel pixel;
	int pos;
	pos = line.find(',');
	pixel.x = stoi(line.substr(0, pos));
	
	line = line.substr(pos+1);

	// repeat this for y, r, g

	pixel.b = stof(line);

	return pixel;


}

void flip_vertically(std::vector<Pixel>&pixel_list){

	int max - 6;

	for (int i = 0; i < pixel_list.size(); i++)
	{

		pixel_list[i].y = (max - 1) - (pixel_lisst[i].y);

	}

}


int main(int argc, char* argv[]){

	std::vector<Pixel>pixel_list;
	std::string line;
	std::ifstream file(" ");

	if (file.is_open()){ 
		
		std::cout << "Opened file " << file << std::endl;
		
		while(getline(file, line)){
		
			std::cout << line << std::endl;
			pixel.list.push_back(make_pixel(line));

		}

		file.close();

	}

	else {

		std::cout << "No source file found... Terminating..." << std::endl;
		return 1;
	}
	



}
