package com.fuzhu.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * @FileName: Gag
 * @author: qianBaoLi
 * @date: 2020/11/28 10:46
 * @Description: null
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Gag {
    private Long id;
    private Date createTime;
    private Date gagTime;
    private User user;

}
