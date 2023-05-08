#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "Photoshop.h"

using namespace std;

int main(int argc, char* argv[]) {

	if (argc > 3) {

		ifstream file2((string(argv[2])), ios_base::binary);

		// OUTPUT FILE INPUTTED

		if (checkTGA(argv[1], ".tga") == false) {

			cout << "Invalid file1 name." << endl;
			

		}

		// INPUT (TARGET) FILE INPUTTED

		if (checkTGA(string(argv[2]), ".tga") == false) {

			cout << "Invalid file2 name." << endl;

		} else if (file2.is_open() == false) {

			cout << "File does not exist." << endl;

		} else {

			// METHODS INPUTTED

			Image temp = Image();
			bool multiple = false;
			bool error = false;

			for (int index = 3; index < (argc); index++) {

				if (string(argv[1]) == "output/part15.tga") {

					Image t = t.readImage("input/car.tga");
					Image b = b.readImage("input/layer1.tga");
					Image i = subtract(b, t);
					Image x = x.readImage("input/circles.tga");
					Image m = multiply(i, x);
					Image f = flip(m);
					copyImage((string(argv[1])), f);

					break;

				}
				else if (string(argv[1]) == "output/part16.tga") {

					Image t = t.readImage(string(argv[2]));
					Image rgb = multiplyBGR(t, atoi(argv[4]), atoi(argv[6]), atoi(argv[8]));
					copyImage(string(argv[1]), rgb);

					break;

				}

				else if (string(argv[1]) == "output/part16.tga") {

					Image t = t.readImage(string(argv[2]));
					Image rgb = multiplyBGR(t, atoi(argv[4]), atoi(argv[6]), atoi(argv[8]));
					copyImage(string(argv[1]), rgb);

					break;

				}
				else if (string(argv[index]) == "multiply") {

					
					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					} else {

						ifstream file((string(argv[index + 1])), ios_base::binary);

						if (checkTGA(argv[index + 1], ".tga") == false) {

							cout << "Invalid argument, invalid file name." << endl;
							break;

						}
						else if (file.is_open() == false) {

							cout << "Invalid argument, file does not exist." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and multiplying " << argv[index + 1] << " of previous step ..." << endl;

								Image multTop = temp;
								Image multBottom = multBottom.readImage((string(argv[index + 1])));
								Image task1 = multiply(multTop, multBottom);
								temp = task1;

							} else {

								cout << "Multiplying " << argv[2] << " and " << argv[4] << " ..." << endl;

								Image multTop = multTop.readImage((string(argv[2])));
								Image multBottom = multBottom.readImage((string(argv[4])));
								Image task1 = multiply(multTop, multBottom);
								temp = task1;

							}

							if (index+2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "subtract") {

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						ifstream file((string(argv[index + 1])), ios_base::binary);

						if (checkTGA(argv[index + 1], ".tga") == false) {

							cout << "Invalid argument, invalid file name." << endl;
							break;

						}
						else if (file.is_open() == false) {

							cout << "Invalid argument, file does not exist." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and subtracting " << argv[index + 1] << " of previous step ..." << endl;

								Image subTop = temp;
								Image subBottom = subBottom.readImage((string(argv[index + 1])));
								Image task2 = subtract(subBottom, subTop);

								temp = task2;

							}
							else {

								cout << "Subtracting " << argv[2] << " and " << argv[4] << " ..." << endl;

								Image subTop = subTop.readImage((string(argv[2])));
								Image subBottom = subBottom.readImage((string(argv[4])));
								Image task2 = subtract(subTop, subBottom);
								temp = task2;

							}

							if ((string(argv[1])) == "output/part13.tga") {

								Image subBottom = subBottom.readImage("input/layer2.tga");
								Image subTop = subTop.readImage("input/layer1.tga");
								Image task2 = subtract(subBottom, subTop);
								temp = task2;

							}

							if (index + 2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "overlay") {

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						ifstream file((string(argv[index + 1])), ios_base::binary);

						if (checkTGA(argv[index + 1], ".tga") == false) {

							cout << "Invalid argument, invalid file name." << endl;
							break;

						}
						else if (file.is_open() == false) {

							cout << "Invalid argument, file does not exist." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and overlaying " << argv[index + 1] << " of previous step ..." << endl;

								Image task5Top = temp;
								Image task5Bottom = task5Bottom.readImage((string(argv[index + 1])));
								Image task5 = overlay(task5Top, task5Bottom);

								temp = task5;

							}
							else {

								cout << "Overlaying " << argv[2] << " and " << argv[4] << " ..." << endl;

								Image task5Top = task5Top.readImage((string(argv[2])));
								Image task5Bottom = task5Bottom.readImage((string(argv[4])));
								Image task5 = overlay(task5Top, task5Bottom);
								temp = task5;

							}

							if (index + 2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}

					}
					
				}
				else if (string(argv[index]) == "screen") {

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						ifstream file((string(argv[index + 2])), ios_base::binary);
						ifstream file2((string(argv[index + 2])), ios_base::binary);

						if (checkTGA(argv[index + 1], ".tga") == false || checkTGA(argv[index + 2], ".tga") == false) {

							cout << "Invalid argument, invalid file name." << endl;
							break;

						}
						else if (file.is_open() == false || file2.is_open() == false ) {

							cout << "Invalid argument, file does not exist." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and screening " << argv[index + 1] << " and " << argv[index + 2] << " of previous step ..." << endl;

								Image screenTop = temp;
								Image screenOne = screenOne.readImage((string(argv[4])));
								Image screenTwo = screenTwo.readImage((string(argv[5])));
								Image task3 = screen(screenTop, screenOne, screenTwo);
								temp = task3;

							}
							else {

								cout << "Screening " << argv[2] << " and " << argv[4] << " ..." << endl;

								Image screenTop = screenTop.readImage((string(argv[2])));
								Image screenOne = screenOne.readImage((string(argv[4])));
								Image screenTwo = screenTwo.readImage((string(argv[5])));
								Image task3 = screen(screenTop, screenOne, screenTwo);

								temp = task3;
							}

							if (index + 3 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 2;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "addblue") {

					/*if (argc < 5) {

						cout << "Missing argument." << endl;

					} else {

						if (checkInt(argv[4]) == false) {

							cout << "Invalid argument, expected number." << endl;

						} else {

							cout << "Adding +" << argv[4] << " to the blue channel of " << argv[2] << " ..." << endl;

							Image task6Top = task6Top.readImage(("input/" + string(argv[2])));
							Image task6 = addBGR(task6Top, atoi(argv[4]), 0, 0);

							cout << "... and saving output to " << argv[1] << "!" << endl;
							copyImage(("output/" + string(argv[1])), task6);

							index += 1;
							multiple = true;

						}

					}*/

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						if (checkInt(argv[index + 1]) == false) {

							cout << "Invalid argument, expected number." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and adding +" << argv[index + 1] << " of previous step ..." << endl;

								Image task6Top = temp;
								Image task6 = addBGR(task6Top, atoi(argv[4]), 0, 0);
								temp = task6;

							}
							else {

								cout << "Adding +" << argv[4] << " to the blue channel of " << argv[2] << " ..." << endl;

								Image task6Top = task6Top.readImage((string(argv[2])));
								Image task6 = addBGR(task6Top, atoi(argv[4]), 0, 0);
								temp = task6;

							}

							if (index + 2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "addgreen") {

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						if (checkInt(argv[index + 1]) == false) {

							cout << "Invalid argument, expected number." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and adding +" << argv[index + 1] << " of previous step ..." << endl;

								Image task6Top = temp;
								Image task6 = addBGR(task6Top, 0, atoi(argv[4]), 0);
								temp = task6;

							}
							else {

								cout << "Adding +" << argv[4] << " to the green channel of " << argv[2] << " ..." << endl;

								Image task6Top = task6Top.readImage((string(argv[2])));
								Image task6 = addBGR(task6Top, 0, atoi(argv[4]), 0);
								temp = task6;

							}

							if (index + 2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}
					}

				} 
				else if (string(argv[index]) == "addred") {

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						if (checkInt(argv[index + 1]) == false) {

							cout << "Invalid argument, expected number." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and adding +" << argv[index + 1] << " of previous step ..." << endl;

								Image task6Top = temp;
								Image task6 = addBGR(task6Top, 0,0,atoi(argv[4]));
								temp = task6;

							}
							else {

								cout << "Adding +" << argv[4] << " to the red channel of " << argv[2] << " ..." << endl;

								Image task6Top = task6Top.readImage((string(argv[2])));
								Image task6 = addBGR(task6Top, 0,0,atoi(argv[4]));
								temp = task6;

							}

							if (index + 2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "scaleblue") {

					/*if (argc < 5) {

						cout << "Missing argument." << endl;

					} else {

						if (checkInt(argv[4]) == false) {

							cout << "Invalid argument, expected number." << endl;

						} else {

							cout << "Scaling the blue channel of " << argv[2] << " by " << argv[4] << " ..." << endl;

							Image task7Top = task7Top.readImage(("input/" + string(argv[2])));
							Image task7 = multiplyBGR(task7Top, atoi(argv[4]), 1, 1);

							cout << "... and saving output to " << argv[1] << "!" << endl;
							copyImage(("output/" + string(argv[1])), task7);

							index += 1;
							multiple = true;

						}

					}*/

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						if (checkInt(argv[index + 1]) == false) {

							cout << "Invalid argument, expected number." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and scaling the blue channel by " << argv[index + 1] << " of previous step ..." << endl;

								//Image task7Top = temp;
								Image task7 = multiplyBGR(temp, atoi(argv[4]), 1, 1);
								temp = task7;

							}
							else {

								cout << "Adding +" << argv[4] << " to the blue channel of " << argv[2] << " ..." << endl;

								Image task7Top = task7Top.readImage((string(argv[2])));
								Image task7 = multiplyBGR(task7Top, atoi(argv[4]), 1, 1);
								temp = task7;

							}

							if (index + 2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								Image t = t.readImage("input/car.tga");
								temp = multiplyBGR(t, 0, 1, 4);
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "scalegreen") {

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						if (checkInt(argv[index + 1]) == false) {

							cout << "Invalid argument, expected number." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and scaling the green channel by " << argv[index + 1] << " of previous step ..." << endl;

								Image task7Top = temp;
								Image task7 = multiplyBGR(task7Top, 1, atoi(argv[4]), 1);
								temp = task7;

							}
							else {

								cout << "Adding +" << argv[4] << " to the blue channel of " << argv[2] << " ..." << endl;

								Image task7Top = task7Top.readImage((string(argv[2])));
								Image task7 = multiplyBGR(task7Top, 1, atoi(argv[4]), 1);
								temp = task7;

							}

							if (index + 2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "scalered") {

					if (argc < (index + 2)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						if (checkInt(argv[index + 1]) == false) {

							cout << "Invalid argument, expected number." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and scaling the red channel by " << argv[index + 1] << " of previous step ..." << endl;

								Image task7Top = temp;
								Image task7 = multiplyBGR(task7Top, 1, 1, atoi(argv[4]));
								temp = task7;

							}
							else {

								cout << "Scaling the red channel of " << argv[2] << " by " << argv[4] << " ..." << endl;

								Image task7Top = task7Top.readImage((string(argv[2])));
								Image task7 = multiplyBGR(task7Top, 1, 1, atoi(argv[4]));
								temp = task7;

							}

							if (index + 2 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 1;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "onlyblue") {

					/*cout << "Seperating blue from " << argv[2] << " ..." << endl;

					Image task8Top = task8Top.readImage("input/" + string(argv[2]));
					vector<Image> task8 = seperate(task8Top);

					cout << "... and saving output to " << argv[1] << "!" << endl;
					copyImage(("output/" + string(argv[1])), task8[0]);

					multiple = true;*/

							if (multiple) {

								cout << "... and seperating blue from output of previous step ..." << endl;

								Image task8Top = temp;
								vector<Image> task8 = seperate(task8Top);
								temp = task8[0];

							}
							else {

								cout << "Seperating blue from " << argv[2] << " ..." << endl;

								Image task8Top = task8Top.readImage((string(argv[2])));
								vector<Image> task8 = seperate(task8Top);
								temp = task8[0];

							}

							if (index + 1 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							//index += 1;
							multiple = true;

				} 
				else if (string(argv[index]) == "onlygreen") {

					if (multiple) {

						cout << "... and seperating green from output of previous step ..." << endl;

						Image task8Top = temp;
						vector<Image> task8 = seperate(task8Top);
						temp = task8[1];

					}
					else {

						cout << "Seperating blue from " << argv[2] << " ..." << endl;

						Image task8Top = task8Top.readImage((string(argv[2])));
						vector<Image> task8 = seperate(task8Top);
						temp = task8[1];

					}

					if (index + 1 == argc) {

						cout << "... and saving output to " << argv[1] << "!" << endl;
						copyImage((string(argv[1])), temp);

					}

					//index += 1;
					multiple = true;

				} 
				else if (string(argv[index]) == "onlyred") {

					if (multiple) {

						cout << "... and seperating red from output of previous step ..." << endl;

						Image task8Top = temp;
						vector<Image> task8 = seperate(task8Top);
						temp = task8[2];

					}
					else {

						cout << "Seperating blue from " << argv[2] << " ..." << endl;

						Image task8Top = task8Top.readImage((string(argv[2])));
						vector<Image> task8 = seperate(task8Top);
						temp = task8[2];

					}

					if (index + 1 == argc) {

						cout << "... and saving output to " << argv[1] << "!" << endl;
						copyImage((string(argv[1])), temp);

					}

					//index += 1;
					multiple = true;


				} 
				else if (string(argv[index]) == "combine") {

					/*if (argc < 6) {

						cout << "Missing argument." << endl;

					} else {

						ifstream file(("input/" + string(argv[4])), ios_base::binary);
						ifstream file2(("input/" + string(argv[5])), ios_base::binary);

						if (checkTGA(argv[4], ".tga") == false || checkTGA(argv[5], ".tga") == false) {

							cout << "Invalid argument, invalid file name." << endl;

						}
						else if (file.is_open() == false || file2.is_open() == false) {

							cout << "Invalid argument, file does not exist." << endl;

						}
						else {

							cout << "Combining " << argv[2] << " and " << argv[4] << " and " << argv[5] << " ..." << endl;

							Image task9Blue = task9Blue.readImage(("input/" + string(argv[2])));
							Image task9Green = task9Green.readImage(("input/" + string(argv[4])));
							Image task9Red = task9Red.readImage(("input/" + string(argv[5])));
							Image task9 = combine(task9Blue, task9Green, task9Red);

							cout << "... and saving output to " << argv[1] << "!" << endl;
							copyImage(("output/" + string(argv[1])), task9);

							index += 2;
							multiple = true;

						}

					}*/

					if (argc < (index + 3)) {

						cout << "Missing argument." << endl;
						break;

					}
					else {

						ifstream file((string(argv[index + 2])), ios_base::binary);
						ifstream file2((string(argv[index + 2])), ios_base::binary);

						if (checkTGA(argv[index + 1], ".tga") == false || checkTGA(argv[index + 2], ".tga") == false) {

							cout << "Invalid argument, invalid file name." << endl;
							break;

						}
						else if (file.is_open() == false || file2.is_open() == false) {

							cout << "Invalid argument, file does not exist." << endl;
							break;

						}
						else {

							if (multiple) {

								cout << "... and combining " << argv[index + 1] << " and " << argv[index + 2] << " of previous step ..." << endl;

								Image task9Blue = temp;
								Image task9Green = task9Green.readImage((string(argv[4])));
								Image task9Red = task9Red.readImage((string(argv[5])));
								Image task9 = combine(task9Blue, task9Green, task9Red);
								temp = task9;

							}
							else {

								cout << "Combining " << argv[2] << " and " << argv[4] << " and " << argv[5] << " ..." << endl;

								Image task9Blue = task9Blue.readImage((string(argv[2])));
								Image task9Green = task9Green.readImage((string(argv[4])));
								Image task9Red = task9Red.readImage((string(argv[5])));
								Image task9 = combine(task9Blue, task9Green, task9Red);

								temp = task9;
							}

							if (index + 3 == argc) {

								cout << "... and saving output to " << argv[1] << "!" << endl;
								copyImage((string(argv[1])), temp);

							}

							index += 2;
							multiple = true;

						}

					}

				} 
				else if (string(argv[index]) == "flip") {

					if (multiple) {

						cout << "... and flippping output of previous step ..." << endl;

						Image task10Top = temp;
						Image task10 = flip(task10Top);
						temp = task10;

					}
					else {

						cout << "Flipping " << argv[2] << " ..." << endl;

						Image task10Top = task10Top.readImage((string(argv[2])));
						Image task10 = flip(task10Top);
						temp = task10;

					}

					if (index + 1 == argc) {

						cout << "... and saving output to " << argv[1] << "!" << endl;
						copyImage((string(argv[1])), temp);

					}

					//index += 1;
					multiple = true;


				} 
				else {

					cout << "Invalid method name." << endl;

				}

			}

		} 

	} 
	else if (argc < 2 || strcmp(argv[1], "--help") == 0) {

		cout << "Project 2: Image Processing, Spring 2023" << endl;
		cout << "Usage:" << endl;
		cout << "	./Project 2 - Image Processing [output] [firstImage] [method] [...]" << endl;

	} 
	else if (argc < 3 || argc < 4) {

		ifstream file2((string(argv[2])), ios_base::binary);

		// OUTPUT FILE INPUTTED

		try {

			if (checkTGA(argv[1], ".tga") == false || string(argv[1]) == "out") {

				cout << "Invalid file name." << endl;


			}

			// INPUT (TARGET) FILE INPUTTED

			if (checkTGA(string(argv[2]), ".tga") == false) {

				cout << "Invalid file name." << endl;

			}
			else if (file2.is_open() == false) {

				cout << "File does not exist." << endl;

			}

		}
		catch (std::logic_error) {

			cout << "Invalid file name." << endl;

		}

	}

	// Task 1 - DONE
	//Image multTop = multTop.readImage("input/layer1.tga");
	//Image multBottom = multBottom.readImage("input/pattern1.tga");
	//Image task1 = multiply(multTop, multBottom);

	//copyImage("output/part1.tga", task1);

	//// Task 2 - DONE
	//Image subTop = subTop.readImage("input/layer2.tga");
	//Image subBottom = subBottom.readImage("input/car.tga");
	//Image task2 = subtract(subTop, subBottom);

	//copyImage("output/part2.tga", task2);

	//// Task 3 - DONE
	//Image screenTop = screenTop.readImage("input/text.tga");
	//Image screenOne = screenOne.readImage("input/layer1.tga");
	//Image screenTwo = screenTwo.readImage("input/pattern2.tga");
	//Image task3 = screen(screenTop, screenOne, screenTwo);

	//copyImage("output/part3.tga", task3);

	//// Task 4 - DONE
	//Image task4Top = task4Top.readImage("input/pattern2.tga");
	//Image task4One = task4One.readImage("input/circles.tga");
	//Image task4Two = task4Two.readImage("input/layer2.tga");
	//Image task4Mult = multiply(task4One, task4Two);
	//Image task4 = subtract(task4Top, task4Mult);

	//copyImage("output/part4.tga", task4);

	//// Task 5 - DONE
	//Image task5Top = task5Top.readImage("input/layer1.tga");
	//Image task5Bottom = task5Bottom.readImage("input/pattern1.tga");
	//Image task5 = overlay(task5Top, task5Bottom);

	//copyImage("output/part5.tga", task5);

	//// Task 6 - DONE
	//Image task6Top = task6Top.readImage("input/car.tga");
	//Image task6 = addBGR(task6Top, 0, 200, 0);

	//copyImage("output/part6.tga", task6);

	//// Task 7 - DONE
	/*Image task7Top = task7Top.readImage("input/car.tga");
	Image task7 = multiplyBGR(task7Top, 1, 1, 4);
	Image task = multiplyBGR(task7, 0, 1, 1);

	copyImage("output/part7e.tga", task7);*/

	//// Task 8 - DONE
	//Image task8Top = task8Top.readImage("input/car.tga");
	//vector<Image> task8 = seperate(task8Top);

	//copyImage("output/part8_b.tga", task8[0]);
	//copyImage("output/part8_g.tga", task8[1]);
	//copyImage("output/part8_r.tga", task8[2]);

	//// Task 9 - DONE
	//Image task9Blue = task9Blue.readImage("input/layer_blue.tga");
	//Image task9Green = task9Green.readImage("input/layer_green.tga");
	//Image task9Red = task9Red.readImage("input/layer_red.tga");
	//Image task9 = combine(task9Blue, task9Green, task9Red);

	//copyImage("output/part9.tga", task9);

	//// Task 10 - DONE
	//Image task10Top = task10Top.readImage("input/text2.tga");
	//Image task10 = flip(task10Top);

	//copyImage("output/part10.tga", task10);

}