/**
 * @description:
 * @author: fox
 * @date: 2020/10/24 16:08
 */

public enum Size {
    SMALL("S"),MEDIUM("m"),LARGE("l"),EXTRA_LARGE("XL");

    private  String abbreviation;

    private Size(String abbreviation) {
        this.abbreviation = abbreviation;
    }

    public String getAbbreviation() {
        return abbreviation;
    }
}
