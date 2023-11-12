import java.util.*;

public class Solution {
    public int convertToInteger(final String str) {
        int result = 0;
        for (int i = 0; i < str.length(); i++) {
            result = result * 10 + (str.charAt(i) - '0');
        }
        return result;
    }

    public boolean isHourDifferenceValid(int startHour, int startMinute, int endHour, int endMinute) {
        int hourDiff = endHour - startHour;
        int minuteDiff = endMinute - startMinute;
        if (hourDiff > 1 || hourDiff < 0) return false;
        if (hourDiff == 1) return endMinute < startMinute;
        return true;
    }

    public List<String> findHighAccessEmployees(List<List<String>> accessTimes) {
        Map<String, List<String>> employeeAccessMap = new HashMap<>();

        for (List<String> access : accessTimes) {
            employeeAccessMap.computeIfAbsent(access.get(0), key -> new ArrayList<>()).add(access.get(1));
        }

        List<String> highAccessEmployees = new ArrayList<>();

        for (Map.Entry<String, List<String>> entry : employeeAccessMap.entrySet()) {
            List<String> accessList = entry.getValue();

            if (accessList.size() > 2) {
                accessList.sort(Comparator.naturalOrder());
                for (int i = 0; i < accessList.size(); ++i) {
                    int count = 0;

                    for (int j = i + 1; j < accessList.size(); ++j) {
                        if (isHourDifferenceValid(
                                convertToInteger(accessList.get(i).substring(0, 2)),
                                convertToInteger(accessList.get(i).substring(2)),
                                convertToInteger(accessList.get(j).substring(0, 2)),
                                convertToInteger(accessList.get(j).substring(2))
                        )) {
                            count++;
                        }
                    }

                    if (count >= 2) {
                        highAccessEmployees.add(entry.getKey());
                        break;
                    }
                }
            }
        }

        return highAccessEmployees;
    }
}
