#include <iostream>
#include <vector>

struct Weather {
    int id;
    std::string recordDate;
    int temperature;
};

std::vector<int> risingTemperature(const std::vector<Weather>& weather) {
    std::vector<int> result;
    for (size_t i = 1; i < weather.size(); ++i) {
        if (weather[i].temperature > weather[i - 1].temperature) {
            
            std::string date1 = weather[i-1].recordDate;
            std::string date2 = weather[i].recordDate;

            int year1 = std::stoi(date1.substr(0,4));
            int month1 = std::stoi(date1.substr(5,2));
            int day1 = std::stoi(date1.substr(8,2));

            int year2 = std::stoi(date2.substr(0,4));
            int month2 = std::stoi(date2.substr(5,2));
            int day2 = std::stoi(date2.substr(8,2));
            
            if(year2 == year1){
                if(month2 == month1){
                    if(day2 == day1+1){
                        result.push_back(weather[i].id);
                    }
                } else if(month2 == month1+1){
                    if(month1==1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12){
                        if(day1 == 31 && day2 == 1){
                            result.push_back(weather[i].id);
                        }
                    } else if(month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11){
                        if(day1 == 30 && day2 == 1){
                            result.push_back(weather[i].id);
                        }
                    }else{
                        if(year1%4 == 0 && (year1%100 !=0 || year1%400 == 0)){
                            if(day1 == 29 && day2 == 1){
                                result.push_back(weather[i].id);
                            }
                        } else {
                            if(day1 == 28 && day2 == 1){
                                result.push_back(weather[i].id);
                            }
                        }
                    }
                }
            }
            
        }
    }
    return result;
}

int main() {
    std::vector<Weather> weatherData = {
        {1, "2015-01-01", 10},
        {2, "2015-01-02", 25},
        {3, "2015-01-03", 20},
        {4, "2015-01-04", 30}
    };

    std::vector<int> risingTemps = risingTemperature(weatherData);

    for (int id : risingTemps) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    return 0;
}