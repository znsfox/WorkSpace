import java.time.LocalDate;

/**
 * @FileName: PairTest2
 * @author: qianBaoLi
 * @date: 2020/11/14 17:45
 * @Description: null
 */
public class PairTest2 {
    public static void main(String[] args) {
        LocalDate[] birthdays = {
                LocalDate.of(1998,3,2),
                LocalDate.of(1993,3,2),
                LocalDate.of(1992,3,2),
                LocalDate.of(1994,3,2),
        };
        Pair<LocalDate> mm = ArrayAlg2.minmax(birthdays);
        assert mm != null;
        System.out.println(mm.getFirst());
        System.out.println(mm.getSecond());
    }

}

class ArrayAlg2 {
    public static <T extends Comparable> Pair<T> minmax(T[] a) {
        if (a.length == 0 || a == null) {
            return null;
        }
        T max = a[0];
        T min = a[0];
        for (int i = 0; i < a.length; i++) {
            if (min.compareTo(a[i]) > 0) {
                min = a[i];
            }
            if (max.compareTo(a[i]) < 0) {
                max = a[i];
            }
        }
        return new Pair<>(min, max);
    }
}
