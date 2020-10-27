package service.impl;

import mapper.RoleMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import pojo.Role;
import service.RoleService;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/8 14:36
 */
@Service
public class RoleServiceImpl implements RoleService {
    RoleMapper roleMapper = null;

    @Autowired
    public RoleServiceImpl(RoleMapper roleMapper) {
        this.roleMapper = roleMapper;
    }

    @Transactional(rollbackFor = Exception.class,propagation = Propagation.REQUIRES_NEW,
            isolation = Isolation.READ_COMMITTED)
    @Override
    public int insertRole(Role role) {
        return roleMapper.insertRole(role);
    }
}
