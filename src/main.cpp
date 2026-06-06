#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

//#include <QLabel>
//No, man. Better learn to update yourself next time.

#include <QLCDNumber>

//#include <QDebug>
//Thank you, QDebug..

#include "timerarray.h"
#include "countdown.h"

//TODO finish
int main(int argc, char *argv[]) {
 //Window setup
 QApplication timergui(argc, argv); //i saw that in the guide, idk if it is needed
 
 QWidget timerwindow; //this is probably needed
 timerwindow.resize(700, 400); //you got it, size
 timerwindow.setWindowTitle("Timer"); //name
 
 //layouts setup
 QVBoxLayout *mainlayout = new QVBoxLayout(&timerwindow); //This is the layout that unites two layouts in one.
 QVBoxLayout *layout = new QVBoxLayout(&timerwindow); //layout for the setup stuff
 QHBoxLayout *layoutfortimer = new QHBoxLayout(&timerwindow); //layout that does actually show time
 
 //buttons, labels, stuff for layout yeah
 QLineEdit *hours = new QLineEdit(&timerwindow); //where you print hours in
 QLineEdit *minutes = new QLineEdit(&timerwindow); //where you print minutes in
 QLineEdit *seconds = new QLineEdit(&timerwindow); //where you print seconds in
 
 QPushButton *enterbutton = new QPushButton("Click me if you're done!", &timerwindow); //and the button you press to start the timer.
 
 //simple setup for the placeholder text. you get it.
 hours->setPlaceholderText("Hours..");
 minutes->setPlaceholderText("Minutes..");
 seconds->setPlaceholderText("Seconds..");
 
 //Labels to display the timer. They were called labels because they used QLabels before
 QLCDNumber *hoursLabel = new QLCDNumber(10, &timerwindow); ///hours
 QLCDNumber *minutesLabel = new QLCDNumber(10, &timerwindow); //minutes
 QLCDNumber *secondsLabel = new QLCDNumber(10, &timerwindow); //seconds
 //make them display what's needed
 hoursLabel->display(timer::ArrayWithUsersHoursMinutesSeconds[0]);
 minutesLabel->display(timer::ArrayWithUsersHoursMinutesSeconds[1]);
 secondsLabel->display(timer::ArrayWithUsersHoursMinutesSeconds[2]);
 
 //final step to setup layouts
 
 //layout for setting up the timer:
 layout->addWidget(hours);
 layout->addWidget(minutes);
 layout->addWidget(seconds);
 layout->addWidget(enterbutton);
 
 //for timer itself:
 layoutfortimer->addWidget(hoursLabel);
 layoutfortimer->addWidget(minutesLabel);
 layoutfortimer->addWidget(secondsLabel);
 
 //and for the main to unite both.
 mainlayout->addLayout(layout);
 mainlayout->addLayout(layoutfortimer);
 
 //Finally, the window isn't naked. It has got its pants and a shirt.
 timerwindow.setLayout(mainlayout);
 
 //this is what happens when you press the button:
 QObject::connect(enterbutton, &QPushButton::clicked, [hours, minutes, seconds]() {
  
  //qDebug() << "The button was pressed wow";
  //Heroes don't wear capes, they just help. I thank you for your service, qDebug().
  
  //int AWUHMS[]  = {hours->text().toInt(),minutes->text().toInt(),seconds->text().toInt()};
  //this was much longer. I removed it. 
  
  ReplaceData(0, hours->text().toInt()); //replacing the global array's hours
  ReplaceData(1, minutes->text().toInt()); //replacing the global array's minutes
  ReplaceData(2, seconds->text().toInt()); //replacing the global array's seconds
  
  //start a countdown:
  countdown(timer::ArrayWithUsersHoursMinutesSeconds[0], timer::ArrayWithUsersHoursMinutesSeconds[1], timer::ArrayWithUsersHoursMinutesSeconds[2]);
  
 });
 
 //and the timer can see you.
 timerwindow.show();
 
 return timergui.exec();
}


