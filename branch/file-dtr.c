//e add ko lang diri mga comment each line for better understanding, the rest I docs ko or readme file.
//kindly read each part and purpose of variables and conditions

//diri nga ang ginatawag nga Header file or preproccessor directive:
#include <stdio.h>//standard input output
#include <conio.h>//console input output
#include <windows.h>//need ni sa for gotoxy and clear screen purposes which is system("cls");

//let's work on a problem that it limits the invalid in the first entered input
//declared constants
#define g gotoxy//everytime mag gamit ta gotoxy 'g' nalng aton gamiton 
#define p printf//same man diri 'p' nalang gamiton
#define s scanf//as well as diri 's' man

//global variables:
int weeklySalary = 0, employee = 1, day = 5, description = 1, ti , to;//ti - time in, to - time out
int  total_undertime = 0, salary_per_hrs = 100, total_late = 0, unfloat_hrs_work;//unfloat hours work gamiton tani sa pag calculate sang hours work sa modulo
//this is float incase there's a decimal in result, para sure gid
float hrs_work = 0, totalWorkhours = 0.0, total_weekly_salary = 0.0, weekly_salary = 0.0, total_work_hours = 0.0;
int late = 0, undertime = 0, total_hrs_work = 0, final_hrs_work = 0;
//variable for conversion of total late && undertime
int total_late_hrs, total_late_min;
int total_undertime_hrs, total_undertime_min;
//varibale for conversion of late && undertime
int undertime_in_hrs, undertime_in_min;
int late_in_hrs, late_in_min;
//variable for conversion of time in time out
int time_in_hrs, time_in_min, time_out_hrs, time_out_min;
//variable for conversion of total hours work
int total_hrs_work_min, total_hrs_work_hrs;
//variable for conversion of hours work && weekly salary
int hrs_work_hrs, hrs_work_min;
int weekly_salary_hrs, weekly_salary_min;
//variable for answer
char ans;
void gotoxy(int x, int y){
//since lain ang turbo c, c droid, sa vs code, sa vs need gid mag ubra function with header file nga "<windows.h>"
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//please memorized kay mawasak aton structure
}
void display_total(){
    g(13, 20);p("total:");
    g(21, 20);p("%0.2d", total_hrs_work_hrs);
    g(23, 20);p(":");
    g(24, 20);p("%0.2d", total_hrs_work_min);
    g(27, 20);p("total:");
    g(35, 20);p("%0.2d", total_late_hrs);
    g(37, 20);p(":");
    g(38, 20);p("%0.2d", total_late_min);
    g(43, 20);p("total:");
    g(51, 20);p("%0.2d", total_undertime_hrs);
    g(53, 20);p(":");
    g(54, 20);p("%0.2d", total_undertime_min);
    g(2, 21);p("Total HW: ");
    g(14, 21);p("%0.2d", total_hrs_work_hrs);
    g(16, 21);p(":");
    g(17, 21);p("%0.2d", total_hrs_work_min);
    g(2, 22);p("Total LATE: ");
    g(14, 22);p("%0.2d", total_late_hrs);
    g(16, 22);p(":");
    g(17, 22);p("%0.2d", total_late_min);
    g(2, 23);p("Total UNDERTIME: ");
    g(19, 23);p("%0.2d", total_undertime_hrs);
    g(21, 23);p(":");
    g(22, 23);p("%0.2d", total_undertime_min);
    g(23, 21);p("WEEKLY SALARIES: ");
    g(40, 21);p("%5.2f", total_weekly_salary);
    another_employee:
    g(27, 23);p("ANOTHER EMPLOYEE? ");
    g(45, 23);s("%s", &ans);
    if (ans == 'n' || ans == 'n'){
        g(2, 24);p("ARE YOU SURE YOU WANT TO EXIT? (y/n) ");
        g(39, 24);s("%s", &ans);
        if (ans == 'Y' || ans == 'y'){
            system("cls");
            exit(0);
        } else {
            g(45, 23);p("      ");
            g(2, 24);p("                                      ");
            goto another_employee;
        }
    } //after all the execution ma kadto na di para mag exit if naka abot sa di means nga ma another employee sya
    //tas nag add nalang ta confirmation para sa another employee in case nga mag change iya mind
    g(30, 24);p("CONFIRM?");
}

void display_description(){//e display naton ang description sini
    g(25, 8);p("EMPLOYEE:");
    g(35, 8);p("%d", employee);//this line may value sya kay interchangeable ina kay ga increment aton nga employee kung mag another employee kita
    g(25, 9);p("PAYROLL FOR THE WEEK");
    g(25, 10);p("DAILY TIME RECORD");
    g(2, 13);p("days");
    g(10, 13);p("AM IN");
    g(20, 13);p("AM OUT");
    g(30, 13);p("HRS WORK");
    g(40, 13);p("LATES");
    g(50, 13);p("UNDERTIME");
}
void timeIn_timeOut(){
    display_description();
    loop:
    for (day = 1; day < 6; day ++){
        time_in_again:
        g(3, 5);printf("HOURS IN");
        g(11, 5);printf(":");
        g(13, 5);printf("MINUTES IN");
        g(28, 5);printf(":");
        g(2, 6);printf("HOURS OUT");
        g(11, 6);printf(":");
        g(13, 6);printf("MINUTES OUT");
        g(28, 6);printf(":");
        g(26, 5);scanf("%d", &time_in_hrs);
        g(2, 7);printf("                       ");
        //a task here!!
        if (time_in_hrs < 5 || time_in_hrs > 12){//so nag add ko sang condition nga sa time in hour palang gina limit nya na ang invalid
            g(26, 5);printf("  ");
            g(2, 7);printf("INVALID INPUT");
            goto time_in_again;
        }
        g(29, 5);scanf("%d", &time_in_min);
        g(2, 7);printf("                       ");
        if (time_in_min < 0 || time_in_min > 59){//same here gina limit nya ang invalid sa time in minutes
            g(26, 5);printf("  ");
            g(29, 5);printf("       ");
            g(2, 7);printf("INVALID INPUT");
            goto time_in_again;
        }
        g(2, 7);printf("                 ");
        ti = time_in_hrs * 60 + time_in_min;
        if (time_in_hrs > 4 && time_in_hrs < 13 && time_in_min > -1 && time_in_min < 60){
            if (ti > 570 && ti < 721){
                if (day < 6){
                    late = 0;
                    undertime = 0;
                    hrs_work = 0;
                    total_hrs_work = total_hrs_work + hrs_work;            
                    total_undertime = total_undertime + undertime;
                    weekly_salary = (hrs_work / 60) * 100;
                    unfloat_hrs_work = hrs_work;
                    total_weekly_salary = total_weekly_salary + weekly_salary;
                    //convertion
                    total_late_hrs = total_late / 60;
                    total_late_min = total_late % 60;
                    //convertion
                    total_undertime_hrs = total_undertime / 60;
                    total_undertime_min = total_undertime % 60;
                    g(10, 13);p("AM IN");
                    g(9, 13 + day);p("%0.2d", time_in_hrs);
                    g(11, 13 + day);p(":"); 
                    g(12, 13 + day);p("%0.2d", time_in_min);
                    g(20, 13);p("AM OUT");
                    g(21, 13 + day);p("0:0");
                    g(30, 13);p("HRS WORK");
                    g(31, 13 + day);p("0:0");
                    g(40, 13);p("LATES");
                    g(41, 13 + day);p("4:0");
                    g(50, 13);p("UNDERTIME");
                    g(51, 13 + day);p("0:0");
                    g(26, 5);printf("  ");
                    g(29, 5);printf("       ");
                    g(26, 6);printf("  ");
                    g(29, 6);printf("       ");
                    g(2, 13+day); p("DAY %d", day);
                    day++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                } 
            }
            time_out_again:
            g(26, 6);scanf("%d", &time_out_hrs);
            g(2, 7);printf("                       ");
            //a task here!!
            if (time_out_hrs < 5 || time_out_hrs > 12){//so nag add ko sang condition nga sa time in hour palang gina limit nya na ang invalid
                g(26, 6);printf("  ");
                g(2, 7);printf("INVALID INPUT");
                goto time_out_again;
            }
            g(29, 6);scanf("%d", &time_out_min);
            g(2, 7);printf("                       ");
            if (time_in_min < 0 || time_in_min > 59){//same here gina limit nya ang invalid sa time in minutes
                g(26, 6);printf("  ");
                g(29, 6);printf("       ");
                g(2, 7);printf("INVALID INPUT");
                goto time_out_again;
            }
            to = time_out_hrs * 60 + time_out_min;
            if (ti > 299 && ti < 451 && to > 689 && to < 721 ){ // scenario 2.0 no late no undertime
                late = 0;
                undertime = 0;
                //convert 
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //convert ta man ang late
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //same man sa hours work
                hrs_work = 240 - undertime - late;
                unfloat_hrs_work = hrs_work;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = unfloat_hrs_work % 60;
                weekly_salary = (hrs_work / 60) * 100;
                total_weekly_salary = total_weekly_salary + weekly_salary;
                //stack
                total_hrs_work = total_hrs_work + hrs_work;    
                total_late = total_late + late;                
                total_undertime = total_undertime + undertime;
                //convertion
                total_hrs_work_hrs = total_hrs_work / 60;
                total_hrs_work_min = total_hrs_work % 60;
                //converetion f
                total_late_hrs = total_late / 60;
                total_late_min = total_late % 60;
                //convertion f
                total_undertime_hrs = total_undertime / 60;
                total_undertime_min = total_undertime % 60;
                if (day < 6){
                    g(10, 13 + day);p("%d", time_in_hrs);
                    g(11, 13 + day);p(":");
                    g(12, 13 + day);p("%0.2d", time_in_min);
                    g(20, 13 + day);p("%0.2d", time_out_hrs);
                    g(22, 13 + day);p(":");
                    g(23, 13 + day);p("%0.2d", time_out_min);
                    g(31, 13 + day);p("%d", hrs_work_hrs);
                    g(32, 13 + day);p(":");
                    g(33, 13 + day);p("%d", hrs_work_min);
                    g(41, 13 + day);p("%d", late_in_hrs);
                    g(42, 13 + day);p(":");
                    g(43, 13 + day);p("%d", late_in_min);
                    g(51, 13 + day);p("%d", undertime_in_hrs);
                    g(52, 13 + day);p(":");
                    g(53, 13 + day);p("%d", undertime_in_min);
                    g(26, 5);printf("  ");
                    g(29, 5);printf("       ");
                    g(26, 6);printf("  ");
                    g(29, 6);printf("       ");
                    g(2, 13 + day); p("DAY %d", day);
                    day ++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                }
            }
            if (ti > 299 && ti < 451 && to > 539 && to < 721){ //scenario 2.1 no late with udertime
                late = 0; 
                undertime = 690 - to;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //convert ta man ang late
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //same man sa hours work
                hrs_work = 240 - undertime - late;
                unfloat_hrs_work = hrs_work;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = unfloat_hrs_work % 60;
                //stack
                total_hrs_work = total_hrs_work + hrs_work;    
                total_late = total_late + late;                
                total_undertime = total_undertime + undertime;
                weekly_salary = (hrs_work / 60) * 100;
                total_weekly_salary = total_weekly_salary + weekly_salary;
                //convertion
                total_hrs_work_hrs = total_hrs_work / 60;
                total_hrs_work_min = total_hrs_work % 60;
                //converetion f
                total_late_hrs = total_late / 60;
                total_late_min = total_late % 60;
                //convertion f
                total_undertime_hrs = total_undertime / 60;
                total_undertime_min = total_undertime % 60;
                if (day < 6){
                    g(10, 13 + day);p("%d", time_in_hrs);
                    g(11, 13 + day);p(":");
                    g(12, 13 + day);p("%0.2d", time_in_min);
                    g(20, 13 + day);p("%0.2d", time_out_hrs);
                    g(22, 13 + day);p(":");
                    g(23, 13 + day);p("%0.2d", time_out_min);
                    g(31, 13 + day);p("%d", hrs_work_hrs);
                    g(32, 13 + day);p(":");
                    g(33, 13 + day);p("%d", hrs_work_min);
                    g(41, 13 + day);p("%d", late_in_hrs);
                    g(42, 13 + day);p(":");
                    g(43, 13 + day);p("%d", late_in_min);
                    g(51, 13 + day);p("%d", undertime_in_hrs);
                    g(52, 13 + day);p(":");
                    g(53, 13 + day);p("%d", undertime_in_min);
                    g(26, 5);printf("  ");
                    g(29, 5);printf("       ");
                    g(26, 6);printf("  ");
                    g(29, 6);printf("       ");
                    g(2, 13 + day); p("DAY %d", day);
                    day ++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                }
            }
            if (ti > 299 && ti < 571 && to > 689 && to < 721){ //scenario 3.0 with late with no udertime
                late = ti - 450; 
                undertime = 0;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //convert ta man ang late
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //same man sa hours work
                hrs_work = 240 - late;
                unfloat_hrs_work = hrs_work;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = unfloat_hrs_work % 60;
                //stack
                total_hrs_work = total_hrs_work + hrs_work;    
                total_late = total_late + late;                
                total_undertime = total_undertime + undertime;
                weekly_salary = (hrs_work / 60) * 100;
                total_weekly_salary = total_weekly_salary + weekly_salary;
                //convertion
                total_hrs_work_hrs = total_hrs_work / 60;
                total_hrs_work_min = total_hrs_work % 60;
                //converetion f
                total_late_hrs = total_late / 60;
                total_late_min = total_late % 60;
                //convertion f
                total_undertime_hrs = total_undertime / 60;
                total_undertime_min = total_undertime % 60;
                if (day < 6){
                    g(10, 13 + day);p("%d", time_in_hrs);
                    g(11, 13 + day);p(":");
                    g(12, 13 + day);p("%0.2d", time_in_min);
                    g(20, 13 + day);p("%0.2d", time_out_hrs);
                    g(22, 13 + day);p(":");
                    g(23, 13 + day);p("%0.2d", time_out_min);
                    g(31, 13 + day);p("%d", hrs_work_hrs);
                    g(32, 13 + day);p(":");
                    g(33, 13 + day);p("%d", hrs_work_min);
                    g(41, 13 + day);p("%d", late_in_hrs);
                    g(42, 13 + day);p(":");
                    g(43, 13 + day);p("%d", late_in_min);
                    g(51, 13 + day);p("%d", undertime_in_hrs);
                    g(52, 13 + day);p(":");
                    g(53, 13 + day);p("%d", undertime_in_min);
                    g(26, 5);printf("  ");
                    g(29, 5);printf("       ");
                    g(26, 6);printf("  ");
                    g(29, 6);printf("       ");
                    g(2, 13 + day); p("DAY %d", day);
                    day ++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                }
            }
            if (ti > 299 && ti < 571 && to > 539 && to < 721){ //scenario 3.1 late with udertime
                late = ti - 450; //240 is 4 hours
                undertime = 690 - to;
                undertime_in_hrs = undertime / 60;
                undertime_in_min = undertime % 60;
                //convert ta man ang late
                late_in_hrs = late / 60;
                late_in_min = late % 60;
                //same man sa hours work
                hrs_work = 240 - undertime - late;
                hrs_work_hrs = hrs_work / 60;
                hrs_work_min = unfloat_hrs_work % 60;
                //stack
                total_hrs_work = total_hrs_work + hrs_work;    
                total_late = total_late + late;                
                total_undertime = total_undertime + undertime;
                weekly_salary = (hrs_work / 60) * 100;
                total_weekly_salary = total_weekly_salary + weekly_salary;
                //convertion
                total_hrs_work_hrs = total_hrs_work / 60;
                total_hrs_work_min = total_hrs_work % 60;
                //converetion f
                total_late_hrs = total_late / 60;
                total_late_min = total_late % 60;
                //convertion f
                total_undertime_hrs = total_undertime / 60;
                total_undertime_min = total_undertime % 60;
                if (day < 6){
                    g(10, 13 + day);p("%d", time_in_hrs);
                    g(11, 13 + day);p(":");
                    g(12, 13 + day);p("%0.2d", time_in_min);
                    g(20, 13 + day);p("%0.2d", time_out_hrs);
                    g(22, 13 + day);p(":");
                    g(23, 13 + day);p("%0.2d", time_out_min);
                    g(31, 13 + day);p("%d", hrs_work_hrs);
                    g(32, 13 + day);p(":");
                    g(33, 13 + day);p("%d", hrs_work_min);
                    g(41, 13 + day);p("%d", late_in_hrs);
                    g(42, 13 + day);p(":");
                    g(43, 13 + day);p("%d", late_in_min);
                    g(51, 13 + day);p("%d", undertime_in_hrs);
                    g(52, 13 + day);p(":");
                    g(53, 13 + day);p("%d", undertime_in_min);
                    g(26, 5);printf("  ");
                    g(29, 5);printf("       ");
                    g(26, 6);printf("  ");
                    g(29, 6);printf("       ");
                    g(2, 13 + day); p("DAY %d", day);
                    day ++;
                    if (day == 6){
                        display_total();
                        break;
                    }
                    goto time_in_again;
                }
            } else {
                g(26, 5);printf("  ");
                g(29, 5);printf("       ");
                g(26, 6);printf("  ");
                g(29, 6);printf("       ");
                g(2, 7);printf("INVALID INPUT");
                goto time_in_again;
            }
        } else {
            g(26, 5);printf("  ");
            g(29, 5);printf("       ");
            g(26, 6);printf("  ");
            g(29, 6);printf("       ");
            g(2, 7);printf("INVALID INPUT");
            goto time_in_again;
        }
    }
}
int main(){
    system("cls");
    do {
        display_description();
        timeIn_timeOut();   
        display_total();
        another_employee:
        //reset ta ang mga value kagina
        weekly_salary = 0.0, total_work_hours = 0.0;
        ti = 0, to = 0, weeklySalary = 0, total_late = 0; 
        total_undertime = 0, salary_per_hrs = 100, unfloat_hrs_work;
        hrs_work = 0, totalWorkhours = 0.0, total_weekly_salary = 0.0;
        late = 0, undertime = 0, total_hrs_work = 0, final_hrs_work = 0;
        employee += 1;
        system("cls");
    } while (ans == 'Y' || ans == 'y');
    system("cls");//clrscr();
    exit(0);
}