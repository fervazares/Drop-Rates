/* Fernando Vazquez
   CS - 1 Final Project
   Drop rate percentage program for scrolls for Summoners War App.
   Name of existing file to analyze is mystical with personal dat gathering
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Rate
{
public:
	Rate();
	void sort();
	void add_data();
	void analyze();
	void calculate();
	void print() const;

private:
	double three;
	double four;
	double five;
	double total;
	double perthree;
	double perfour;
	vector<double> data;
	double perfive;
};

Rate::Rate()
{
	three = 0;
	four = 0;
	five = 0;
	perthree = 0;
	perfour = 0;
	perfive = 0;
	total = 0;
}

void Rate::sort()
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == 3)
		{
			three++;
			total++;
		}
		else if (data[i] == 4)
		{
			four++;
			total++;
		}
		else if (data[i] == 5)
		{
			five++;
			total++;
		}
	}
}

void Rate::add_data()
{
	bool add = false;
	bool fresh = false;

	cout << "1 to create new data, 0 to continue adding to existing data. " << endl;
	int ans;
	cin >> ans;

	if (ans == 1)
	{
		fresh = true;
		while (fresh)
		{
			cout << "What do you want to name your file? " << endl;
			string file;
			cin >> file;

			ofstream clean;
			clean.open(file + ".txt");

			cout << "Begin inputing data, 0 to quit. \n3 for 3* (common) 4 for 4* (uncommon) 5 for 5* (rare): " << endl;

			while (clean.is_open())
			{
				int n1;
				cin >> n1;
				clean << n1 << endl;

				if (n1 == 0)
				{
					clean.close();
					fresh = false;
				}
			}
		}
	}

	else if (ans == 0)
	{
		add = true;
		while (add)
		{
			cout << "What is the name of the file you want to add to? " << endl;
			string ofile;
			cin >> ofile;

			ofstream dirty;
			dirty.open(ofile + ".txt", ios::app);

			cout << "Begin appending data, 0 to quit. \n3 for 3* (common) 4 for 4* (uncommon) 5 for 5* (rare): " << endl;

			while (dirty.is_open())
			{
				int n2;
				cin >> n2;
				dirty << n2 << endl;

				if (n2 == 0)
				{
					dirty.close();
					add = false;
				}
			}
		}
	}
	else
		cout << "Not a valid option. " << endl;
}

void Rate::analyze()
{
	cout << "File name of data set to analyze: " << endl;
	string final;
	cin >> final;

	ifstream input_file(final + ".txt");

	if (input_file)
	{
		double value;

		while (input_file >> value)
		{
			data.push_back(value);
		}
	}
}
void Rate::calculate()
{
	perthree = (three / total) * 100;
	perfour = (four / total) * 100;
	perfive = (five / total) * 100;
}

void Rate::print() const
{
	cout << "----------According to this data----------" << endl;
	cout << "Out of " << total << " summons, the droprates are as follows: " << endl;
	cout << setw(8) << setprecision(2) << fixed << "Number of 3*: " << three << ". Percentage: " << perthree << "%" << endl;
	cout << setw(8) << setprecision(2) << fixed << "Number of 4*: " << four << ". Percentage: " << perfour << "%" << endl;
	cout << setw(8) << setprecision(2) << fixed << "Number of 5*: " << five << ". Percentage: " << perfive << "%" << endl;

	cout << setprecision(2) << fixed << "\n1 out of " << 1 / (perthree / 100) << " scrolls will yield a 3*. " << endl;
	cout << setprecision(2) << fixed << "1 out of " << 1 / (perfour / 100) << " scrolls will yield a 4*. " << endl;
	cout << setprecision(2) << fixed << "1 out of " << 1 / (perfive / 100) << " scrolls will yield a 5*. " << endl;

}

int main()
{
	Rate mystical;

	cout << "Input Data(i) or Analyze Data(a): " << endl;
	char resp;
	cin >> resp;

	if (resp == 'i')
	{
		mystical.add_data();
	}
	else if (resp == 'a')
	{
		mystical.analyze();
		mystical.sort();
		mystical.calculate();
		mystical.print();
	}

	else
		cout << "ERROR!!! Not a valid option." << endl;

	system("pause");

}