package com.fuzhu.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * @FileName: User
 * @author: qianBaoLi
 * @date: 2020/11/27 15:44
 * @Description: null
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class User {
    //用户id
    private Long id;
    //账号
    private String account;
    //头像
    private String avatar;
    //充值总额
    private Long payMoney;
    //国家
    private String country;

    //用户创建时间
    private Date createTime;
    //积分
    private Long score;

    //所在纬度
    private Double latitude;
    //所在经度
    private Double longitude;
    //省份
    private String province;
    //用户性别，F:女，M:男
    private String sex;
    //密码
    private String password;
//    //排名
//    private Integer rank;
}
