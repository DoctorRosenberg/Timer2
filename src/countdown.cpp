#include "countdown.h"

#include <chrono>
#include <thread>

#include <QDebug>

#include "timerarray.h"

//TODO finish
void countdown(int &hours, int &minutes, int &seconds) {
 int WaitTimeSeconds = hours*3600+minutes*60+seconds;
 
 while (!(WaitTimeSeconds == 0)) {
  hours = WaitTimeSeconds / 3600;
  minutes = (WaitTimeSeconds % 3600) / 60;
  seconds = WaitTimeSeconds % 60;
 
  //ReplaceData(0, hours);
  //ReplaceData(1, minutes);
  //ReplaceData(2, seconds);
  
  qDebug() << timer::ArrayWithUsersHoursMinutesSeconds[0] << timer::ArrayWithUsersHoursMinutesSeconds[1] << timer::ArrayWithUsersHoursMinutesSeconds[2];
  --WaitTimeSeconds;
  std::this_thread::sleep_for(std::chrono::seconds(1));
 }
}

