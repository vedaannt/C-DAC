class Date {

    private int day;
    private int month;
    private int year;

    public void setDay(int dd, int mm, int yyyy) {

        int maxDays;

        if (mm == 2) {

            if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0)) {

                maxDays = 29;

            }
            else {

                maxDays = 28;
            }
        }
        else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {

            maxDays = 30;
        }
        else if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {

            maxDays = 31;
            
        }
        else {

            System.out.println("Invalid Month");
            return;
        }

        if (dd >= 1 && dd <= maxDays) {

            day = dd;
            month = mm;
            year = yyyy;
        }
        else {

            day = 1;
            month = mm;
            year = yyyy;
        }
    }
    
    
    public void addDays(int days) {

        for (int i = 1; i <= days; i++) {

            day++;

            int maxDays;

            if (month == 2) {

                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                    maxDays = 29;
                }
                else {
                    maxDays = 28;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {

                maxDays = 30;
            }
            else {

                maxDays = 31;
            }

            if (day > maxDays) {

                day = 1;
                month++;

                if (month > 12) {

                    month = 1;
                    year++;
                       
                    
                }
         
           
            }
        }
    }
    
    
    
    public void addMonths(int months) {

        for (int i = 1; i <= months; i++) {

            month++;

            if (month > 12) {
                month = 1;
                year++;
            }

            int maxDays;

            if (month == 2) {

                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                    maxDays = 29;
                }
                else {
                    maxDays = 28;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {

                maxDays = 30;
            }
            else {

                maxDays = 31;
            }

            if (day > maxDays) {
                day = maxDays;
            }
        }
    }
    
    
    public void addYears(int years) {

        year = year + years;

        if (month == 2 && day == 29) {

            if (year % 400 != 0 && (year % 4 != 0 || year % 100 == 0)) {

                day = 28;
            }
        }
    }
    
    
   

    public void display() {

        System.out.println(day + "/" + month + "/" + year);
    }
}








