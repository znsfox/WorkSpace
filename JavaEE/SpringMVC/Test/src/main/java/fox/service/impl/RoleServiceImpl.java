package fox.service.impl;

import fox.dao.RoleDao;
import fox.pojo.Role;
import fox.pojo.RoleParams;
import fox.service.RoleService;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/29 14:46
 */
@Service
@MapperScan(annotationClass = Repository.class, basePackages = "fox.dao")
public class RoleServiceImpl implements RoleService {

    @Autowired
    private RoleDao roleDao = null;
    @Override
    @Transactional(rollbackFor = Exception.class,isolation = Isolation.READ_COMMITTED,propagation = Propagation.REQUIRED)
    public List<Role> findRoles(RoleParams roleParams) {
        return roleDao.findRoles(roleParams);
    }

    @Override
    public int insertRole(Role role) {
        return roleDao.insertRole(role);
    }

    @Override
    public Role getRole(Long id) {
        return roleDao.getRole(id);
    }

}
