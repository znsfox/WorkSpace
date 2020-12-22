package fox.dao;

import fox.pojo.Role;
import fox.pojo.RoleParams;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/29 14:49
 */
@Repository
public interface RoleDao {
    public List<Role> findRoles(RoleParams roleParams);
    public int  insertRole(Role role);
    public Role getRole(Long id);

}
