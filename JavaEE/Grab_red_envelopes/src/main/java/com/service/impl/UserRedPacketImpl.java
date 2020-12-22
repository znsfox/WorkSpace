package com.service.impl;

import com.dao.RedPacketDao;
import com.dao.UserRedPacketDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import com.pojo.RedPacket;
import com.pojo.UserRedPacket;
import com.service.UserRedPacketService;

/**
 * @FileName: UserRedPacketImpl
 * @author: qianBaoLi
 * @date: 2020/11/19 19:25
 * @Description: null
 */
@Service
public class UserRedPacketImpl implements UserRedPacketService {

    @Autowired
    private RedPacketDao redPacketDao = null;

    @Autowired
    private UserRedPacketDao userRedPacketDao = null;

    private static final int FAILED  = 0;

    @Transactional(rollbackFor = Exception.class,isolation = Isolation.READ_COMMITTED,
    propagation = Propagation.REQUIRED)
    @Override
    public int grapRedPacket(Long redPacketId, Long userId) {
        RedPacket redPacket = new RedPacket();
        redPacket = redPacketDao.getRedPacket(redPacketId);
        if (redPacket.getStock() > 0) {
            redPacketDao.decreaseRedPacket(redPacketId);
            //generate the information of grabbing RedPackets
            UserRedPacket userRedPacket = new UserRedPacket();
            userRedPacket.setAmount(redPacket.getUnitAmount());
            userRedPacket.setUserId(userId);
            userRedPacket.setNote("抢红包" + redPacketId);
            //insert the information of Grabbing RedPackets
            int result = userRedPacketDao.grapRedPacket(userRedPacket);
            return result;
        }
        return FAILED;
    }
}
