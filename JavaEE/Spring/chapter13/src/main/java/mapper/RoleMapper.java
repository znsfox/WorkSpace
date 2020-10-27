package mapper;

import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;
import pojo.Role;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/4 9:55
 */

@Repository
public interface RoleMapper {
    public int insertRole(Role role);

}
