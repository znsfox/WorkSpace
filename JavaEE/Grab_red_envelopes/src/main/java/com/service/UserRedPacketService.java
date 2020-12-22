package com.service;

/**
 * @FileName: UserRedPacketService
 * @author: qianBaoLi
 * @date: 2020/11/19 17:08
 * @Description: null
 */
public interface UserRedPacketService {
    /**
     * store the information of RedPacket
     * @param redPacketId the number of RedPakcet
     * @param userId the number of person who grap the redPacket
     * @return affect the number
     */
    public int  grapRedPacket(Long redPacketId, Long userId);
}
