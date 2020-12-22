package fox.pojo;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/29 14:38
 */
public class RoleParams {
    private String roleName;
    private String note;

    // 分页参数
    private PageParams pageParams = null;

    public String getRoleName() {
        return roleName;
    }

    public void setRoleName(String roleName) {
        this.roleName = roleName;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }

    public PageParams getPageParams() {
        return pageParams;
    }

    public void setPageParams(PageParams pageParams) {
        this.pageParams = pageParams;
    }
}
