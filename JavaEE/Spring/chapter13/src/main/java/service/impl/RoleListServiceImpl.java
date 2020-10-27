package service.impl;

import org.apache.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import pojo.Role;
import service.RoleListService;
import service.RoleService;

import java.util.List;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/8 11:16
 */

@Service
public class RoleListServiceImpl implements RoleListService {
      RoleService roleService = null;

    @Autowired
    public void setRoleService(RoleService roleService) {
        this.roleService = roleService;
    }

    Logger logger = Logger.getLogger(RoleListServiceImpl.class);
    @Override
    @Transactional(rollbackFor = Exception.class,propagation = Propagation.REQUIRED, isolation = Isolation.READ_COMMITTED)
    public int insertRoleList(List<Role> roleList) {
        int count = 0;
        for (Role role : roleList) {
            try {
                count += roleService.insertRole(role);
            } catch (Exception exception) {
                logger.info(exception);
            }
        }
        return count;
    }
}
