/* PyramidCount: Use a recursive function to calculate the number of
 *  required blocks necessary to make a square pyramid in Minecraft,
 *  with a filled in base, and using the fewest amount of blocks.
 *
 *	Usage: pyramidcount.exe
 *  	(c) Zach Hedges, 2012
 */

#include <iostream>

// forward declaration of our function
int PyramidCount(int sidelength);

int main(int argc, char** argv)
{
	int sum, len;
 
	std::cout << "Enter the length of the side: ";
	
	std::cin >> len;
	std::cin.sync();
	
	std::cout << std::endl;
	
	if (len < 3)
	{
		std::cout << "ERROR: Cannot make a pyramid this small." << std::endl;
		return 1;
	}
	
	sum = len * len + PyramidCount(len - 2);
	
	std::cout << "To make a pyramid whose base is "<<len<<" blocks to a side, you'll need: " << std::endl
		<< sum << " Blocks" << std::endl;
		
	std::cout << "Press any key to exit...";
	
	std::cin.get();
	return 0;
}

int PyramidCount(int sidelength)
{
	switch(sidelength)
	{
		case 1:
			return 1;
			break;
		case 2:
			return 4;
			break;
		default:
			return (((sidelength * 4) - 4) + PyramidCount(sidelength - 2));
	}
}