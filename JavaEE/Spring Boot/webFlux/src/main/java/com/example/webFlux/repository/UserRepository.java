package com.example.webFlux.repository;

import com.example.webFlux.entity.User;
import org.springframework.data.mongodb.ReactiveMongoDatabaseFactory;
import org.springframework.data.mongodb.repository.ReactiveMongoRepository;

/**
 * @FileName: UserRepository
 * @author: qianBaoLi
 * @date: 2020/12/1 19:45
 * @Description: null
 */
public interface UserRepository extends ReactiveMongoRepository<User,String> {
}
