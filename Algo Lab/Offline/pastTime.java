import java.time.Instant;
import java.time.ZoneId;
import java.time.ZonedDateTime;

public class pastTime {

    public static void main(String[] args) {
        long posted = 1604768520000L;
        long now = System.currentTimeMillis();
        long diff = now - posted;
        long diffSeconds = diff / 1000;
        long diffMinutes = diffSeconds / 60;
        long diffHours = diffMinutes / 60;
        long diffDays = diffHours / 24;
        long diffWeeks = diffDays / 7;
        long diffMonths = diffDays / 30;
        long diffYears = diffDays / 365;
        if (diffYears > 0)
            System.out.println(diffYears + " years ago");
        else if (diffMonths > 0)
            System.out.println(diffMonths + " months ago");
        else if (diffWeeks > 0)
            System.out.println(diffWeeks + " weeks ago");
        else if (diffDays > 0)
            System.out.println(diffDays + " days ago");
        else if (diffHours > 0)
            System.out.println(diffHours + " hours ago");
        else if (diffMinutes > 0)
            System.out.println(diffMinutes + " minutes ago");
        else
            System.out.println("Just now");
    }
}