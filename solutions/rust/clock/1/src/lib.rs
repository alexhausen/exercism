use std::fmt;

#[derive(PartialEq, Debug)]
pub struct Clock {
    hours: i32,
    minutes: i32,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let mut h = hours;
        let mut m = minutes;
        if (m < 0) {
            if (m == -60) {
                m = 0;
            }
            h = (h + (m / 60)) - 1;
            m = (60 + (m % 60)) % 60;
        } else {
            h = h + (minutes / 60);
            m = minutes % 60;
        }
        
        if h < 0 {
            h = (24 + (h % 24)) % 24;
        } else {
            h = h % 24;
        }
        Clock{hours:h, minutes: m}
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Clock::new(self.hours, self.minutes + minutes)
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{:02}:{:02}", self.hours, self.minutes)
    }
}
