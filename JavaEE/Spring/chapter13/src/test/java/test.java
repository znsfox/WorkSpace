import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import pojo.Role;
import service.RoleListService;


import java.util.ArrayList;
import java.util.List;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/8 15:19
 */
public class test {
    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-cfg.xml");
        RoleListService roleListService = context.getBean(RoleListService.class);
        List<Role> roleList = new ArrayList<>();
        for (int i = 1; i <= 5; i++) {
            Role role = new Role();
            role.setNote("role_note" + i);
            role.setRoleName("role_name" + i);
            roleList.add(role);
        }
        int count = roleListService.insertRoleList(roleList);
        System.out.println(count);
    }
    
}
