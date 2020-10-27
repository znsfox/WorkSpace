package service.impl;

import dao.RoleDao;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import pojo.Role;
import service.RoleService;

import java.beans.Expression;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/15 10:11
 */
@Service
@MapperScan(basePackages = "dao.RoleDao")
public class RoleServiceImpl implements RoleService {

    @Autowired
    private RoleDao roleDao = null;

    @Override
    @Transactional(isolation = Isolation.READ_COMMITTED, propagation = Propagation.REQUIRED)
    public Role getRole(Long id) {
        return roleDao.getRole(id);
    }

}
