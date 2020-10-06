import mapper.RoleMapper;
import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import pojo.Role;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/4 17:38
 */
public class test {
    public static void main(String[] args) {
        testSqlSessionFactoryTemplate();
        //testRoleMapper();
    }

    public static void testSqlSessionFactoryTemplate() {
        ApplicationContext ctx = new ClassPathXmlApplicationContext("spring-cfg.xml");
        //ctx为Spring IoC容器
        SqlSessionTemplate sqlSessionTemplate = ctx.getBean(SqlSessionTemplate.class);
        Role role = new Role();
        role.setRoleName("role_name_sqlSessionTemplate");
        role.setNote("note_sqlSessionTemplate");
        sqlSessionTemplate.insert("mapper.RoleMapper.insertRole", role);
        Long id = role.getId();
      //  System.out.println((char[]) sqlSessionTemplate.selectOne("mapper.RoleMapper.getRole", id));
        role.setNote("update_sqlSessionTemplate");
        sqlSessionTemplate.update("mapper.RoleMapper.updateRole", role);
       // System.out.println((char[]) sqlSessionTemplate.selectOne("mapper.RoleMapper.getRole", id));
    }
    public static void testSpringAndMyBatis() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-cfg.xml");
        RoleMapper roleMapper = context.getBean(RoleMapper.class);
        Role role = new Role();
        role.setRoleName("role_name_mapper1");
        role.setNote("note_mapper1");
        roleMapper.insertRole(role);
        Long id = role.getId();
        roleMapper.getRole(id);
        role.setNote("note_mapper_update2");
        roleMapper.updateRole(role);
    }

    public static void testRoleMapper() {
        ApplicationContext ctx = new ClassPathXmlApplicationContext("spring-cfg.xml");
        RoleMapper roleMapper = ctx.getBean(RoleMapper.class);
        roleMapper.getRole(2L);
        System.out.println(roleMapper.getRole(1L));
    }
}
