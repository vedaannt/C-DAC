#include <iostream>
using namespace std;

int range(double range){
	if(range < 0){
		return -1;
	}
	else if(range >= 0 && range <= 29){
		return 0;
	}
	else if(range >= 30 && range <= 44){
		return 1;
	}
	else if(range >= 45 && range <= 59){
		return 2;
	}
	else{
		return 3;
	}
}

int statusLabel(int statusCode){

	switch(statusCode){
		case -1:
			cout << "Status : SENSOR_ERROR" << endl;
			cout << "Action : Sensor fault - check wiring" << endl;
			break;
		case 0:
			cout << "Status : NORMAL" << endl;
			cout << "Action : No action required" << endl;
			break;
		case 1:
			cout << "Status : WARNING" << endl;
			cout << "Action : Alert sent to supervisor" << endl;
			break;
		case 2:
			cout << "Status : CRITICAL" << endl;
			cout << "Action : Cooling system triggered" << endl;
			break;
		default:
			cout << "Status : SHUTDOWN" << endl;
			cout << "Action : Emergency shutdown initiated" << endl;
			break;
		}
}

int main() {
	double reading;
	cout << "Enter the sensor reading" << endl;
	cin >> reading;

	double Far = (reading * 9 / 5) + 32;
	cout << "Temp : " << reading << "C /" << Far << "F" << endl;

	double statusCode  = range(reading);
	statusLabel(statusCode);

	(reading > 25)? cout << "Above Average" : cout << "Below Average" << endl;
	return 0;
}
