class Solution:
    def find_day(self, s, pref_days):
        month = int(s[0:2])
        day = int(s[3:])
        return pref_days[month-1] + day
        
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        pref_days = [0]*13
        pref_days[1] = 31

        for i in range(2, 13):
            pref_days[i] = pref_days[i-1] + months[i-1]
        
        arriveAliceDay = self.find_day(arriveAlice, pref_days)
        leaveAliceDay = self.find_day(leaveAlice, pref_days)
        arriveBobDay = self.find_day(arriveBob, pref_days)
        leaveBobDay = self.find_day(leaveBob, pref_days)

        min_start_day = max(arriveAliceDay, arriveBobDay)
        min_end_day = min(leaveAliceDay, leaveBobDay)

        days =  (min_end_day - min_start_day) + 1 

        if days < 0:
            return 0
        return days