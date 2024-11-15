using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrainingRecords.Core.Shared;
public interface IRepositoryBase<T> : IDisposable
{
    /// <summary>
    /// Returns the connection to the database
    /// </summary>
    /// <returns>
    /// DbConnection
    /// </returns>
    DbConnection GetDbconnection();

    /// <summary>
    /// Inserts an entity of type <typeparamref name="T"/> into the database
    /// </summary>
    /// <param name="entity">Entity to be inserted</param>
    /// <returns>
    /// Void
    /// </returns>
    void AddEntity(T entity);

    /// <summary>
    /// Updates an entity of type <typeparamref name="T"/> in the database
    /// </summary>
    /// <param name="entity">Entity to be updated</param>
    /// <returns>
    /// Void
    /// </returns>
    void UpdateEntity(T entity);

    /// <summary>
    /// Deletes an entity of type <typeparamref name="T"/> from the database
    /// </summary>
    /// <param name="entity">Entity to be deleted</param>
    /// <returns>
    /// Void
    /// </returns>
    void DeleteEntity(T entity);
}