class Solution {
public:
    string intToRoman(int num) {
        
        string thousand[] = {"","M","MM","MMM"};
        string hundred[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ten[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string unit[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        
        
        return (thousand[num/1000] + hundred[(num%1000)/100] + ten[(num%100)/10] + unit[num%10]);
        
    }
};