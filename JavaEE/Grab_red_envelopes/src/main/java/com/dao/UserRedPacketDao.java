package com.dao;

import org.springframework.stereotype.Repository;
import com.pojo.UserRedPacket;

/**
 * @FileName: UserPacketDao
 * @author: qianBaoLi
 * @date: 2020/11/19 17:03
 * @Description: null
 */
@Repository
public interface UserRedPacketDao {
    /**
     * grap the RedPacket
     * @param userRedPacket the information of grapRedPacket
     * @return affect the records
     */
    public int  grapRedPacket(UserRedPacket userRedPacket);
}
