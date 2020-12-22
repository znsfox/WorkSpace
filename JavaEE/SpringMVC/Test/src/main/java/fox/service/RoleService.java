package fox.service;

import fox.pojo.Role;
import fox.pojo.RoleParams;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/29 14:46
 */
@Repository
public interface RoleService {
    public List<Role> findRoles(RoleParams roleParams);
    public int insertRole(Role role);
    public Role getRole(Long id);

}
