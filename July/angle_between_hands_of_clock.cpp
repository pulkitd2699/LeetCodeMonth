// Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double temp = abs(0.5*(60*hour+minutes) - 6*minutes);
        return (temp > 180) ? 360 - temp : temp;
    }
};