package dao;

import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;
import pojo.Role;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/15 9:52
 */
@Mapper
@Repository
public interface RoleDao {
    public Role getRole(Long id);
}
